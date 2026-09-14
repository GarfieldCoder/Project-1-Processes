COP4634 Project 1

Files (Part 1)
-----
- myshell.cpp: displays the prompt, reads commands, and calls the parser.
- parse.cpp / parse.hpp: split commands into tokens and identify special syntax.
- param.cpp / param.hpp: store parsed arguments, redirects, and background status.
- test_part1.cpp: runs four preliminary parser test cases.
- Makefile: builds myshell with -g and -Wall and provides a test target.

Build and use on the UWF Linux server (!)
-------------------------------------
    make
    ./myshell
    ./myshell -Debug
    make clean
Without -Debug, myshell parses each command and shows another prompt without printing the parsed fields.
Type exit to quit.

Git and GitHub from the UWF SSH server (KNOW HOW TO USE SFTP)
--------------------------------------
To download the project onto the server for the first time:

    git clone https://github.com/GarfieldCoder/Project-1-Processes.git
    cd Project-1-Processes

If the project is already on the server, open its directory and get the
latest changes:

    cd ~/Project-1-Processes
    git pull

VS Code Remote SSH 
------------------
Install Microsoft's Remote SSH extension in Visual Studio Code, connect to
the UWF SSH host, and open this server-side project folder. VS Code provides a
visual file explorer to access repo on UWF's server.

Testing Latest Branch
------------------
In appropiate terminal: 
    make
    ./myshell -Debug
    make test
    ./test_part1
    make clean
