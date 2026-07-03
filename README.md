# A hand-made One Time Pad toolset
## As seen on numberstations around the world

Generate One Time pads in bulk or individually.

Encode and decode from file or enter pad manually.

## random:

```
./random # Output the pad to terminal
options:
-n number of hex pairs per pad
-f filename
-b number of batch files to make
```

## otpgen:

```
./otpgen # Enter pad manually and enter message
./otpgen <file> # Reads pad from <file> and asks for message
```

## otpdec:

```
./otpdec # Enter pad manually and enter received message
./otpdec <file> # Reads pad from <file> and enter received message
```
