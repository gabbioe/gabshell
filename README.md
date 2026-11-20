# LSH (C Shell)

A minimal POSIX command-line shell written in C. It implements a read-parse-execute loop capable of running built-in commands and launching external programs via POSIX process control (`fork`, `execvp`, and `waitpid`).

## Features

- **Interactive Command Loop**: Prompts with `> `, reads arbitrarily long input lines via dynamic heap reallocation, splits input on whitespace delimiters (`" \t\r\n\a"`), and executes commands until `exit` is invoked.
- **Built-in Commands**:
  - `cd <directory>`: Changes the current working directory of the shell process using `chdir`.
  - `help`: Displays shell usage instructions and lists available built-in commands.
  - `exit`: Terminates the shell loop and exits cleanly.
- **External Program Execution**: Resolves and launches external executables found in `PATH` by forking a child process, replacing its image with `execvp`, and waiting for process termination with `waitpid`.

## Building and Running

### Using `make`

```sh
make
./build/lsh
```

To remove build artifacts:

```sh
make clean
```

### Compiling Directly

```sh
cc -Wall -Wextra -Iinclude src/*.c -o lsh
./lsh
```
