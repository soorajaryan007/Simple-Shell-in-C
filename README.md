# Simple-Shell-in-C
This shell will execute basic Linux commands and provide features like changing directories, running background processes, and exiting the shell.

 Simple Shell

 Overview
A minimal command-line shell written in C that allows users to execute basic Linux commands, change directories, and manage processes. This project demonstrates system-level programming concepts like process control, file handling, and command parsing.

---

 Features
1. Execute Linux Commands:
   - Run commands like `ls`, `pwd`, `echo`, etc.
   - Supports multiple arguments (e.g., `ls -l`).

2. Change Directory (`cd`):
   - Navigate the filesystem with the `cd` command.
   - Prints an error if the directory does not exist.

3. Exit Command:
   - Use `exit` to terminate the shell.

4. Background Processes:
   - Commands with `&` at the end run in the background (optional feature).

5. Error Handling:
   - Displays error messages for invalid commands or arguments.

---

 Compilation and Execution

 Prerequisites
- GCC compiler
- Linux operating system

 Steps
1. Save the code as `simple_shell.c`.
2. Compile the code using:
   ```bash
   gcc -o simple_shell simple_shell.c
   ```
3. Run the shell:
   ```bash
   ./simple_shell
   ```

---

 Usage

 Example Commands
```bash
shell> pwd
/home/user

shell> ls -l
total 4
-rwxr-xr-x 1 user user 12345 Nov 27 10:00 simple_shell

shell> cd ..
shell> pwd
/home

shell> exit
Exiting shell...
```

 Background Processes (Optional Feature)
Run commands in the background using `&`:
```bash
shell> sleep 5 &
```

---

 Code Structure
 Functions
1. `read_command()`:
   - Reads user input from the command line.
   - Tokenizes input into the command and its arguments.

2. `execute_command()`:
   - Forks a new process to execute the given command.
   - Waits for the child process to complete unless running in the background.

3. `change_directory()`:
   - Implements the `cd` command to change the current working directory.

4. `main()`:
   - Main program loop to read, process, and execute commands until `exit` is called.

---

 Enhancements
Consider extending the shell with the following features:
1. Piping:
   - Support commands like `ls | grep .c`.

2. Input/Output Redirection:
   - Handle `>` and `<` for file redirection.

3. Environment Variables:
   - Implement commands like `export` and `$PATH`.

4. Command History:
   - Add a history feature to allow cycling through previous commands.

---

 License
This project is open-source and available for educational purposes. Feel free to modify and expand the code as needed.


