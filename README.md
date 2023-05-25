# Project Pipex

Pipex is a project that aims to replicate the functionality of the shell command `pipe` in the C programming language. It allows you to redirect the output of one command as input to another command, similar to using the pipe operator (`|`) in the shell. This README provides instructions on installing, using, and understanding the project, as well as acknowledging the individuals who contributed to its development.

## Installation

To install and use Pipex, follow these steps:

1. Clone the Pipex repository from GitHub:
   ```
   git clone https://github.com/username/pipex.git
   ```

2. Change into the project directory:
   ```
   cd pipex
   ```

3. Compile the Pipex program using the provided Makefile:
   ```
   make
   ```

4. The `pipex` executable will be generated. You can now start using Pipex.

Note: Pipex requires a Unix-like operating system and a C compiler (e.g., GCC) to be installed on your system.

## Usage

To use Pipex, follow the syntax:

```
./pipex file1 cmd1 cmd2 file2
```

- `file1`: The input file to be read and used as input for `cmd1`.
- `cmd1`: The first command to be executed. Its output will be piped as input to `cmd2`.
- `cmd2`: The second command to be executed. It will receive the output of `cmd1` as input.
- `file2`: The output file where the final result will be saved.

Example usage:

```
./pipex infile "ls -l" "wc -l" outfile
```

This command will execute `ls -l` on `infile`, redirect its output to `wc -l`, and save the final result in `outfile`.

## Documentation

Pipex provides a few features and considerations to keep in mind:

- The project uses the standard C library and system calls to manage file descriptors, process execution, and input/output redirection.
- Error handling is implemented to ensure proper reporting of any encountered errors.
- Pipex follows the sequential execution order of `cmd1` and `cmd2`. It does not support multiple pipes or complex command chains.
- The project has been designed to handle common use cases but may not cover all possible scenarios.

For further details on the implementation and code structure, refer to the source code comments and documentation provided within the Pipex repository.

## Credits

This project was completed by Thibault GIRAUDON (tgiraudo) as part of the curriculum at École 42.
