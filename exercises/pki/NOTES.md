sudo openssl req -newkey rsa:2048 -nodes -keyout private.key -x509 -days 365 -out mywebsite.crt
sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout etc/ssl/private/private.key -out etc/ssl/certs/selfsigned.crt
