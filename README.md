# A hand-made One Time Pad toolset
## As seen on numberstations around the world

Generate One Time pads in bulk or individually.

Encode and decode from file or enter pad manually.

## random:

```
./random # Output the pad to terminal
./random -n <filename> # Creats or writes the pad to <filename>
./random -b <number> # Creats <number> ammount of pads
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
