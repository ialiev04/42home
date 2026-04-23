# Minishell

This project has been created as part of the 42 curriculum by yuerliu and ilaliev. I (ilaliev) am responsible for the execution logic in this project.

## Description

**Minishell** is a 42 school project that tasks students with creating a simplified version of a real shell (like Bash). The goal is to develop a command-line interpreter that can execute commands, manage environment variables, and handle complex redirections and pipes.

### Key Features

* **Prompt Display:** Shows a prompt while waiting for a new command.
* **Command Execution:** Searches and launches executables based on the `PATH` variable or relative/absolute paths.
* **Built-ins:** Implementation of `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
* **Redirections:**
* `<` redirects input.
* `>` redirects output.
* `<<` (heredoc) reads input until a delimiter is seen.
* `>>` redirects output in append mode.


* **Pipes:** The `|` operator connects the output of one command to the input of the next.
* **Environment Variables:** Handles `$` expansion and `$?` for the exit status of the last pipeline.
* **Signals:** Management of `Ctrl-C`, `Ctrl-D`, and `Ctrl-\` to match Bash behavior.

## Instructions

### Requirements

This project requires the **Readline** library. To install it on a 42 Mac, you may need to use `brew`:

```bash
brew install readline

```

### Compilation

The project includes a `Makefile` with the standard rules. To compile, run:

```bash
make

```

### Usage

Once compiled, launch the shell with:

```bash
./minishell

```

You can then type commands as you would in a normal terminal:

```bash
minishell$ ls -l | grep "txt" > output.txt
minishell$ export VAR=hello
minishell$ echo $VAR

```

## Resources

### Documentation & Articles

* [A project to introduce you to depression](https://github.com/zstenger93/minishell?tab=readme-ov-file): Overview of minishell
* [minishell overview by gzovkic and dreule](https://foregoing-loan-6f5.notion.site/Minishell-75e85da6eec74129b14eac810c01c686): Introduction to minishell.
* [Let's build a super simple shell in C](https://www.youtube.com/watch?v=yTR00r8vBH8): Introduction to minishell.
* [minishell playlist](https://www.youtube.com/watch?v=83M5-NPDeWs&list=PL7_TuD9ZDMhg5uLHLyd8em13XBKfjzCzR): introduction to core concepts of minishell.
* `man` pages: `execve`, `fork`, `wait`, `pipe`, `dup2`, `sigaction`.

### Use of AI

AI was used in the following capacity during this project:

* **Parser Design:** I used AI to brainstorm the structure of the Abstract Syntax Tree (AST) vs. a simple Command Table to determine the most efficient way to handle nested pipes.
* **Signal Handling:** Consulted AI to understand why `readline` requires a specific hook (`rl_event_hook` or `rl_replace_line`) to properly refresh the prompt after a `SIGINT`.
* **Edge Case Identification:** Used AI to generate a list of "stress test" commands (e.g., empty pipes `| |`, unclosed quotes, or multiple redirects) to verify the robustness of the lexer.
* **Code Review:** AI was used to explain specific `errno` behaviors when `execve` fails due to permission issues.

---
