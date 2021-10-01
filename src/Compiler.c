#include "Declarations/Declarations.h"
#include "Declarations/GlobalState.h"
#include "Declarations/MethodDeclarations.h"
#include "Declarations/StructDeclarations.h"
#include <apaz-libc.h>

const char *usageMesasge =
    "Stilts v0.1\n"
    "Usage:\n"
    "  -h --help : Display this message and exit.\n"
    "\n"
    "Pipeline Flags:\n"
    "  --tokenize : Only tokenize the target file.\n"
    "  --parse    : Only tokenize and create an AST of the target file.\n"
    "  --check    : Only validate the types/syntax of the target file.\n"
    "  --codegen  : Only tokenize/parse/check the source file, and output a .c "
    "file.\n"
    "  --compile  : Execute the whole pipeline and produce a binary (defaut).\n"
    "\n"
    "C Compiler Flags:\n"
    "  --CC       : Specify which C compiler to use (System CC by default).\n"
    "  --cflags   : Specify which flags to give to the C compiler.\n\n";

// Lambdas
static inline void str_destroy(String s, void *none) { String_destroy(s); }
static inline bool filterEmpty(String str, void *extra) {
  (void)extra;
  bool empty = str[0] == '\0';
  if (empty)
    String_destroy(str);
  return !empty;
}

// Helpers
static inline void arg_err(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}
static inline void usage() {
  // Consumes.
  int ex = puts(usageMesasge);
  destroyFlags();
  print_heap();
  exit(ex);
}

static inline void parseFlags(int argc, char **argv) {
  cmdFlags.temp_folder = "/tmp/stilts/";
  cmdFlags.CC = "cc";
  cmdFlags.cflags = List_String_new_cap(0);
  cmdFlags.targets = List_Target_new_cap(1);
  cmdFlags.parse = true;
  cmdFlags.check = true;
  cmdFlags.codegen = true;
  cmdFlags.compileC = true;

  bool grabNext = false;
  if (argc <= 1) {
    usage();
  } else {
    for (size_t i = 1; i < argc; i++) {
      // Skip the argument if it has already been captured, and do what the
      // previous arg says.
      if (grabNext) {
        grabNext = false;

        if (apaz_str_equals(argv[i - 1], "--CC")) {
          cmdFlags.CC = String_new_of_strlen(argv[i]);
          continue;
        } else if (apaz_str_equals(argv[i - 1], "--cflags")) {
          String sarg = String_new_of_strlen(argv[i]);
          List_String_destroy(cmdFlags.cflags);
          cmdFlags.cflags = List_String_filter(String_split(sarg, " "), filterEmpty, NULL);
          String_destroy(sarg);
          continue;
        }
      }

      // Help flag
      else if (apaz_str_equals(argv[i], "-h") |
               apaz_str_equals(argv[i], "--help")) {
        usage();
      }

      // Pipeline Flags
      else if (apaz_str_equals(argv[i], "--tokenize"))
        cmdFlags.parse = false;
      else if (apaz_str_equals(argv[i], "--parse"))
        cmdFlags.check = false;
      else if (apaz_str_equals(argv[i], "--check"))
        cmdFlags.codegen = false;
      else if (apaz_str_equals(argv[i], "--codegen"))
        cmdFlags.compileC = false;

      // Compiler Flags
      else if (apaz_str_equals(argv[i], "--CC")) {
        if (i == argc)
          arg_err("--CC requires an argument (The C compiler to use).");
        grabNext = true;
      } else if (apaz_str_equals(argv[i], "--cflags")) {
        if (i == argc)
          arg_err("--cflags requires an argument (The flags to pass to the C compiler, all in one arg).");
        grabNext = true;
      }

      // Targets
      else {
        Target t = {.file_name = argv[i]};
        cmdFlags.targets = List_Target_addeq(cmdFlags.targets, t);
      }
    }
  }

  cmdFlags.cflags = List_String_trim(cmdFlags.cflags);
  cmdFlags.targets = List_Target_trim(cmdFlags.targets);
}

static inline void destroyFlags() {
  List_String_foreach(cmdFlags.cflags, str_destroy, NULL);
  List_Target_destroy(cmdFlags.targets);
}

static inline const char *strb(bool b) { return b ? "yes" : "no"; }
static inline void printFlags() {
  printf(
      "Command Line Flags:\n\n    /* Pipeline Options */\n    parse:   %s\n   "
      " check:   %s\n    codegen: %s\n    compile: %s\n\n",
      strb(cmdFlags.parse), strb(cmdFlags.check), strb(cmdFlags.codegen),
      strb(cmdFlags.compileC));

  puts("    /* Codegen Options */");
  printf("    CC:      %s\n", cmdFlags.CC);
  printf("    cflags:  [");
  if (List_String_len(cmdFlags.cflags))
    printf("%s", cmdFlags.cflags[0]);
  for (size_t i = 1; i < List_String_len(cmdFlags.cflags); i++)
    printf(", %s", cmdFlags.cflags[i]);
  printf("]\n");

  printf("    targets: [");
  if (List_Target_len(cmdFlags.targets))
    printf("%s", cmdFlags.targets[0].file_name);
  for (size_t i = 1; i < List_Target_len(cmdFlags.targets); i++)
    printf(", %s", cmdFlags.targets[i].file_name);
  printf("]\n\n");
  fflush(stdout);
}

int main(int argc, char **argv) {
  parseFlags(argc, argv);
  printFlags();
  destroyFlags();
  print_heap();
}