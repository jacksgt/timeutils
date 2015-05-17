# Timeutils
A compilation of different tools focused around accessing time on *nix Systems.

Currently included:
- up
- runtime

## up
Prints the uptime of the system (time since last reboot).
Command line options:
```
--grep # easily grepable format
--sentence # prints a complete sentence
--help # prints usage as well as available command line options
```

How to compile:
```bash
cd up;
gcc main.c -o up
sudo cp up /usr/local/bin # install, (optional step)
```

## runtime
Monitors and manages the total uptime (runtime) if the system.

Command line options:
```
--print-seconds # prints the total runtime in seconds (no writing)
--print-uptime # prints the uptime (/proc/uptime) of the system (no writing)
```

How to compile:
```bash
cd runtime;
gcc main.c fileio.c -o runtime;
sudo cp runtime /usr/local/bin # install (optional step)
```

## Feedback
Please leave me any thoughts you have. Suggestions are always welcome.
