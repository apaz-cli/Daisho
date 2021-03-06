
# Parse Flags
* Determine how much of the pipeline to execute
* Determine base compiler flags (More are parsed from code)
* Determine all .dai/.daisho target files


# Load Files
* For each target file in parallel:
	* Read the contents into memory
	* Put into structure for PackCC


# Parse
* For each file's contents in parallel:
	* Create an allocator for nodes and associated information.
	* Call the initial parsing rule, parse_CompilationUnit().
		* This calls other recursively decendng grammar rules in sequence.
		* Each grammar rule carefully manages the parser's state.
			* Each grammar rule takes the parser as an argument, and returns a pointer to the node allocated by
			  malloc(), or NULL.
			* Fragments are parsing rules which should not create an AST in the finished product,
			  and therefore must be freed immediately. They are useful, for example, for parsing
			  argument lists.
			* When parsing a rule fails (as most will), free the memory.
		* If in a compilation unit a parse is requred to succeed and fails (syntax error), capture the state of the
		  parser, the position in the token stream, return an error, and exit the thread. This way, each compilation
		  unit can report up to one syntax error, and it's deterministic which one is found and the order they are
		  reported.

# Validate AST
### Pass one:
For each compilation unit in parallel:
	* Sort the root of the tree's (the compilation unit's) children by their type (Functions, Classes, Traits,
	  Global variables, cflags, etc), and then by their name.
	* Traverse the tree for its leaves and handle literals:
		* Combine String literals. Ex: "Hello " "World" "!"
		* Validate that float and integer literals can fit.
			* These are in the EN-ASCII subset, so casting characters works.
		* Determine the values of literals by parsing the unicode and converting.
			* Unicode in strings must be escaped.
	* Pull out all the trait, function, class, and type names from the root of each. Keep track of how far nested you
	  found them.


# Semantic/Type Analysis


# Generic Monomorphization


# Static Analysis
* Validate that duplicate typedefs don't define the type differently, then replace with the real type.
* Build a hierarchy of types.
    * Circular and multiple template implements are okay, but make sure they're handled.
* Infer Generics, keeping a note. Native methods cannot accept or return generics, but can be in a generic class.
* Traverse the AST, starting from the bottom.
    * Validate types and combine values known at compile time.
    * Apply widening conversions automatically. Disallow narrowing conversions without a cast.
	* Integer types can cast to float types, except ULong to Float, because it is narrowing.
    * Infer the return values of functions by their signature (mindful that overloads exist).
* Validate Interfaces are implemented and types match

!!! DANGER PEPEGA INCOMING
	1. Make a pass over every translation unit and pull out the type definitions and their trait requirements. This can be yoinked directly from the abstract syntax tree. Also pull out associated generic types and their bounds within that context. Include the content of all `impl` blocks, with their own contexts.

 	2. Creatively reorder such that the next step works. We can because no cyclical trait dependencies are allowed.

	3. Trace for each type that, if they're telling the truth about what they are/can do everything is consistent.

	4. Check method signatures to make sure they report to fulfill their trait requirements by tracing each type's hierarchy. While we're at it do the same for class member variables.

	5. Trace each type in the signature to make sure it is consistent. Do the same for class member variables.

	6. For each statement in each method in order, mark the type of each expression. Perform widening and narrowing conversions as necessary. Check invocations of traits. Keep track of which are invoked.

	7. Build a table for each type of each of its invocations for the code generator.


# Code Generator
Tables must be generated for the following:

* Write all type declarations
* Write all ctype declarations
* Write all function declarations
* Write all native function declarations

* Write all struct definitions
* Write all function definitions
* Include all native


