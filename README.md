# Timeutils
A compilation of different tools focused around accessing time on *nix Systems.

Currently included:
- up

## up
Prints the uptime of the system (time since last reboot).
Command line options:
```
--grep # easily grepable format
--sentence # prints a complete sentence
--help # prints usage as well as available command line options
--seconds # prints only the seconds of the uptime (nothing else)
```

How to compile:
```bash
cd up;
gcc main.c -o up
sudo cp up /usr/local/bin # install, (optional step)
```

## Feedback
Please leave me any thoughts you have. Suggestions are always welcome.
