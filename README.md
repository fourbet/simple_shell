# **SIMPLE SHELL**

## Synopsis

Simple shell is an interface inspired by sh that executes command read from the standard input.

## Description

Obviously this is our own version of sh we can execute commands with their arguments , some basics built-in
and it run in interactive and non-interactive mode :

**First we compile all .c files**
```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
----
Once run we can use the executable file "hsh" in two mode.

**Non-interactive mode :**
```bash
$ echo "ls -la" | ./hsh
```
**Interactive mode :**
```bash
$ ./hsh
$ ls -la
```

## How this simple shell work ?

When you type a command the programm will looking for the absolute path of your command and executed it if he's present in the environment.
```bash
(pwd) will be executed by simple shell as (/bin/pwd)
```
If he find the path, all arguments are obviously taken into account.

---

If the command doesn't exist the simple shell will display the exact same error message than sh.

***Exemple :***
```bash
$ Hey my name is Betty
$ sh: (order of classification): Hey: not found
```
There is also built-in who are very useful in case the environment is destroy.<br>
**Built-in** are used to executed something even when the environment is empty.<br>
There is only one way to call a built-in and that is by **typing his name.**

```bash
$ env
(display environment)
```

```bash
$ exit
(ends the programm)
```

## Built-in commands

| Command | Description  |
| ------- | --- |
| exit | Exit from simple shell|
| help | Display help of built-in command |
| env | Display environment variables and their value |
| cd | Change directory |
| setenv | Set environment variable value or create a new one |
| unsetenv | Delete environment variable |


## Exit status


Terminate the shell process, if status is given the echo $? will print the value of status


## Authors

***Ophélie* FOURBET**  ~~ https://github.com/fourbet <br>
***Tarek* KHEIR**      ~~ https://github.com/tarekkheir
