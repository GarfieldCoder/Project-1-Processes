COP4634 Project 1

Files (So far)
-----
- myshell.cpp: contains main() and initializes the program variables.
- parse.cpp / parse.hpp: contain the command-line parser interface.
- param.cpp / param.hpp: contain the Param class implementation and definition.
- Makefile: builds the required executable named myshell with -g and -Wall.

Build and use on the UWF Linux server (!)
-------------------------------------
    make
    ./myshell
    ./myshell -Debug
    make clean

Git and GitHub from the UWF SSH server
--------------------------------------
In the project directory:

    git init
    git add .
    git commit -m "Add Project 1 scaffold"
    git branch -M main
    git status
    git add .
    git commit -m "Describe the change"
    git push

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
