## Generating Key Pairs

$ cd ./keys

$ ssh-keygen -t rsa -b 4096 -C '<your-name>@up.edu' -f ./hw

Enter any passphrase you want

$ chmod 700 ../keys

$ chmod 644 ./hw.pub

$ chmod 600 ./hw

$ ls -l

You should see two files. The file hw file is your private key. Don't share it and keep it private. You will use that file to encrypt your homework. The hw.pub file is your public key. Give a copy of that file to your instructor. The instructor will use that file to decrypt your homework. If you lose your private key, regenerate key and provide to update public one to your instructor.

## Signing Homework with Your Private Key

Create a zip file as instructed in your homework assignment. For our example here, let's call it hw.zip.



