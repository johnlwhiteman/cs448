## TLS Handshake

### Instructions

Start Kali Linux
Open a terminal
$ firefox &
$ wireshark


$ ifconfig

Select you primary inteface to external connection ... probably eth0

$ wireshark

Wait for application to load

Double click eth0 (or whatever interface)
In Firefox go to https://google.com

In Wireshark type "tls" in the filter

Close Browser

Menu -> Capture -> Stop (or press the red button)

Menu -> File -> Save As -> (give any name you like)
