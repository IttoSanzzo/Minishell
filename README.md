<p align="center"><img src="https://i.imgur.com/lBg3XT1.png" alt="Minishell Artwork"></p>

## About It

-   It is a fully functional [Shell for Linux Terminals](https://pt.wikipedia.org/wiki/Shell_do_Unix), and works just as any other famous shell, with features primarily based on [Bash](https://pt.wikipedia.org/wiki/Bash), [Zsh](https://pt.wikipedia.org/wiki/Z_shell) and [Fish](<https://en.wikipedia.org/wiki/Fish_(Unix_shell)>).
-   It was done in the [C Programming Language](<https://pt.wikipedia.org/wiki/C_(linguagem_de_programa%C3%A7%C3%A3o)>) for the [Rio's Ecolle 42](https://42.rio) minishell project.
-   Also, there where some limitations, regarding libraries permitted or not, and according to [42's Coding Norme](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf), imposed in the project.

## Some Features

-   Perfectly capable of parsing a prompt and launching executables with arguments.
-   It as suport to piping between executables.
-   Any common token will work as intended, except for `&&` and `||`, which weren't needed, but won't cause any error.
-   Quotes like `""` and `''` work the same as [Bash](https://pt.wikipedia.org/wiki/Bash).
-   You can separate commands with `;`, as well as use redirections `>`, `<`, `>>`, `<<` and pipes `|`.
-   Environment variables are handled, and expand to it's values when used, like `$HOME`, including the return code `$?`.
-   You can use `Ctrl-C` to interrupt and `Ctrl-\` to quit a program, as well as `Ctrl-D` to throw an EOF, same as in bash.
-   A few of the built-in functions where made as well, meaning we don't call the executable, I re-coded them directly. It's the case for `echo`, `pwd`, `cd`, `env`, `export`, `unset` and `exit`.

## Usage

-   You will need the external "[readline](https://tiswww.case.edu/php/chet/readline/rltop.html)" library installed in your machine.
-   It functions just as any other shell program would. Simply clone the repository, and then compile it using `make`. It will then generate a `minishell` executable.
-   Running this program will change the shell you're currently in, to the minishell.

```Bash
./minishell
```

-   In it, you're able to do about anythink you would be in another common shell, for example, using commands from the enviromental path, such as `ls`, `echo`, and `exit`, which ends the program.

<img src="https://i.imgur.com/wxL7g3U.png" alt="Minishell Commands Example">

-   And as the minishell was done to be able to recognize terminal signals, it can be ended pressing `CTRL-D` as well, like Bash.

## Using it as default Shell

To use it as your default Shell, you will need to, either:

-   Move the executable to the /bin/bash directory, and then change your Terminals default shell to it, if it's supported.

or

-   Add a line containing `/path/to/executable/minishell` to the end of whatever "rc" file your current Shell uses. For example, if it's Bash, then you will need to add that line at the end of your `~/.bashrc` file.

---

<p align="center"> Done with a lot of 💜... aand C, by <a href="https://github.com/IttoSanzzo">IttoSanzzo</a>.</p>
