# minishell Environement
--
Variable

Environement variable change his name by his value
 - $PATH
 - ${PATH}

```bash
$ echo $USER
-> mhaman
echo ${USER}
-> mhaman
```

Single and double quotes
---
Single quote protect the value it contains and express it as a string
double quote does not protect the value

- " "	Double quote
- ' '	Single quote

```bash
$ echo '$USER'
->	'$USER'
$ echo "${USER}"
->	mhaman
$ ec'ho' "Bonjour"
->	Bonjour
$ echo tutu      tata
->	tutu tata
$ echo "tutu    tata"
->	tutu    tata
```

Redirect
---
Redirection change the way the command is write/read

- < Redirect to intput and read
- \> Redirect to output and write
- \>> Redirect to output and write to the end

```bash
# Redirige la sortie dans un fichier
$ echo tutu > test.txt
$ cat text.txt
->	tutu
# Redirige la sortie dans un fichier et ecrit a la suite
$ echo tata >> test.txt
$ cat test.txt
->	tutu
->	tata

# Envoie le contenu de text.txt dans cat
$ cat < test.txt
->	tutu
->	tata
# A differencier de
$ cat test.txt
->	tutu
->	tata
# cette formulation va recuperer le file descriptor de test.txt pour l'afficher
```
Backslash
---
Backslash cancel the property of the last character

- \

```bash
#Fonctionnement Normal
$ echo tutu > test.txt
$ cat test.txt
->	tutu
$ echo $USER
-> mhaman
#Fonctionnement Backslash
$ echo tutu    \>  test.txt
->	tutu > test.txt
$ echo \$USER
-> $USER
```

Pipe et semi colon
---
Pipe and semi colon allow you to use multiple command on an single line

- | Send output of the first command to the second
-  ; Stop the current command and move to the next one

```bash
$ time | echo tutu
->	tutu
->	shell  0.00s user 0.00s system 0% cpu 7:14:31.23 total
->	children  0.00s user 0.00s system 0% cpu 7:14:31.23 total

$ echo tutu ; ls ; pwd ; echo fin
->	tutu
->	. ..
->	/home/mhaman/Minishell
->	fin
```

Particular Case
--
```bash
# Dans ce cas la sortie est modifier deux fois
$ echo Bonjour > tutu Salut > tata
$ cat tutu
# Le fichier tutu est bien cree mais est vide
$ cat tata
->	Bonjour Salut
```
