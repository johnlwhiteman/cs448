Start Kali2020 VM

Open a terminal

```
$ sudo dhclient eth0
$ ifconfig eth0  # Mine is 192.168.192.148
```

Start Metasploitable2 VM
```
$ ifconfig eth0 # Mine is 192.168.192.128
```

Note that both IPs should start with 192.168.192.* AND if not then check on Kali the ip for eth1

**[@ Kali2020]**
```
$ cd ~/cs448-2020/exercises
$ git pull
$ cd ~/cs448-2020/exercises/iptables
$ nmap 192.168.192.128 # May take a minute or two to complete scanning
                       # You may need to specify nmap -e <eth0|eth1> <ip>
```

You should see output similar to this

```
PORT     STATE SERVICE                                                                                                                          
21/tcp   open  ftp
22/tcp   open  ssh
23/tcp   open  telnet
25/tcp   open  smtp
111/tcp  open  rpcbind
139/tcp  open  netbios-ssn
445/tcp  open  microsoft-ds
512/tcp  open  exec
513/tcp  open  login
514/tcp  open  shell
1099/tcp open  rmiregistry
1524/tcp open  ingreslock
2121/tcp open  ccproxy-ftp
3306/tcp open  mysql
5432/tcp open  postgresql
5900/tcp open  vnc
6000/tcp open  X11
6667/tcp open  irc
8009/tcp open  ajp13
8180/tcp open  unknown
```

**[@ Kali2020]**

Let's try telnet from Kali to Metasploitable
```
$ telnet 192.168.192.128 # might take up to 30-60 seconds to show prompt```

Enter credentials as msfadmin/msfadmin

If you maded it this far then telnet appears to working

```
$ exit
```

**[@ Metasploitable2]**

Let's configure our firewall to filter network traffic from using telnet
$ sudo iptables -A INPUT -p tcp --dport 23 -j REJECT
$ sudo iptables -A OUTPUT -p tcp --sport 23 -j REJECT
$ sudo iptables -t filter -L


**[@ Kali2020]**

Let's see if it is filtered
$ map -sV -p 23 192.168.192.128

You should see output like this ...

Starting Nmap 7.80 ( https://nmap.org ) at 2020-02-20 16:28 EST
Nmap scan report for 192.168.192.128
Host is up (0.00067s latency).

PORT   STATE SERVICE VERSION
23/tcp open  telnet  Linux telnetd
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 23.34 seconds


**[@ Metasploitable2]**

Now let's configure our firewall to completely drop the packet without sending a response
$ sudo iptables -A INPUT -p tcp --dport 23 -j DROP
$ sudo iptables -A OUTPUT -p tcp --sport 23 -j DROP
$ sudo iptables -t filter -L


**[@ Kali2020]**
Let's see if it closed or filtered
$ map -sV -p 23 192.168.192.128

You should see output like this ...

```
Starting Nmap 7.80 ( https://nmap.org ) at 2020-02-20 16:28 EST
Nmap scan report for 192.168.192.128
Host is up (0.00067s latency).

PORT   STATE SERVICE VERSION
23/tcp **open**  telnet  Linux telnetd
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 23.34 seconds
```


REJECT
Sends a reply ICMP packet telling the requestor that its packet was rejected

DROP
Drops the packet without sending a response

Which is best?
DROP is better than REJECT since the latter can be susceptible to DoS attacks
Remember that it still needs to create a ICMP packet which takes resources
However, both show as "filtered" in NMAP tool
This lets the attacker now the service is probably still running
BEST to completely disable and remove the service is possible 




# Port States


**Open:** An application is actively accepting TCP connections, UDP datagrams or SCTP associations on this port. Finding these is often the primary goal of port scanning. Security-minded people know that each open port is an avenue for attack. Attackers and pen-testers want to exploit the open ports, while administrators try to close or protect them with firewalls without thwarting legitimate users. Open ports are also interesting for non-security scans because they show services available for use on the network.


**Closed:** A closed port is accessible (it receives and responds to Nmap probe packets), but there is no application listening on it. They can be helpful in showing that a host is up on an IP address (host discovery, or ping scanning), and as part of OS detection. Because closed ports are reachable, it may be worth scanning later in case some open up. Administrators may want to consider blocking such ports with a firewall. Then they would appear in the filtered state, discussed next.


**Filtered:** Nmap cannot determine whether the port is open because packet filtering prevents its probes from reaching the port. The filtering could be from a dedicated firewall device, router rules, or host-based firewall software. These ports frustrate attackers because they provide so little information. Sometimes they respond with ICMP error messages such as type 3 code 13 (destination unreachable: communication administratively prohibited), but filters that simply drop probes without responding are far more common. This forces Nmap to retry several times just in case the probe was dropped due to network congestion rather than filtering. This slows down the scan dramatically.


**Unfiltered:** The unfiltered state means that a port is accessible, but Nmap is unable to determine whether it is open or closed. Only the ACK scan, which is used to map firewall rulesets, classifies ports into this state. Scanning unfiltered ports with other scan types such as Window scan, SYN scan, or FIN scan, may help resolve whether the port is open.


**Open|Filtered:** Nmap places ports in this state when it is unable to determine whether a port is open or filtered. This occurs for scan types in which open ports give no response. The lack of response could also mean that a packet filter dropped the probe or any response it elicited. So Nmap does not know for sure whether the port is open or being filtered. The UDP, IP protocol, FIN, NULL, and Xmas scans classify ports this way.


**Closed|Filter:** This state is used when Nmap is unable to determine whether a port is closed or filtered. It is only used for the IP ID idle scan.



In a nutshell (Think of the Three-Way-Handshake):


A client issues a SYN and the server replies with SYN/ACK then the port is OPEN


A client issues a SYN and the server replies with RST then the port is CLOSE


A client issues a SYN and the server replies with ICMP then it means the port is being FILTERED or blocked by a firewall






