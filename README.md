## run

This is a cli tool that monitors the directory the program is run in and when change is discovered, then runs the specified command.

## Getting started

```sh
gcc -o run run.c
```

## Examples

```sh
./run "printf 'hey\n'"
./run printf "\"hey\n\""
./run ls -Ahl
./run "ls" "-Ahl"
./run "ls -Ahl;" "printf 'hey\n'"
./run "ls -Ahl;" printf "'hey\n'"
```

## TODOs

* improve the change monitoring

## Author

Meelis Utt
