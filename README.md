# Terminal-Titan
Terminal Titan is a simple command-line tool for a UNIX-like shell in Windows. This tool allows you to perform basic file and directory operations, as well as execute external commands.

## Installation

To install Terminal Titan, simply download or clone this repository to your local machine and open it.
```bash
git clone https://github.com/ayushch80/Terminal-Titan.git
cd Terminal-Titan/src
```

Then, compile the code using a C compiler of your choice.

```bash
gcc main.c print_prompt.c list_directory.c print_file_contents.c -o ../build/terminal_titan
```

## Usage

To use Terminal Titan, simply navigate to the directory containing the compiled terminal_titan executable and run the following command:

```bash
./terminal_titan
```

This will start the Terminal Titan shell, where you can enter commands.
## Commands

Terminal Titan supports the following commands:

-    `exit`: Exits the Terminal Titan shell.
-    `cd [directory]`: Changes the current working directory. If no directory is specified, changes to the user's home directory.
-    `ls [directory]`: Lists the contents of the current directory or the specified directory.
-    `cat [file]`: Prints the contents of the specified file.
-    External commands: You can execute any external command by simply typing it in the Terminal Titan shell. For example, `echo "Hello, World!`".

## License

This project is licensed under the MIT License - see the ![LICENSE.md](LICENSE.md) file for details.
