## Installation
```
$ cd ~/cs448-2020/exercises/passwords
$ ./setup
```

## Cracking Your Password

```
$ cd ~/cs448-2020/exercises/passwords
$ umask 077
$ cat /etc/passwd
$ sudo cat /etc/shadow
$ sudo unshadow /etc/passwd /etc/shadow > mypasswords
$ cat mypasswords
$ john mypasswords
```
// Open another terminal
```
cd ~/cs448-2020/exercises/passwords
john --show mypasswords

```
// Did your password get cracked? If so ... too weak!
// Kill john by ctrl-c

## Cracking Other Passwords
```
$ cat ./badpasswords
$ john ./badpasswords
```
// Let it run for a minute or two
// Open another terminal
```
cd ~/cs448-2020/exercises/passwords
john --show badpasswords
```

You should see 100 or so passwords hacked




