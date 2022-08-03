<h1> simple_shell</h1>
	
Date: July of 2022.

<h2>NAME:</h2> 
simple_shell - command language interpreter

<h2> Synopsis </h2>
  


<h2> Description </h2>
The sh utility is a command language interpreter that shall
execute commands read from a command line string, the standard
input, or a specified file.

<h2> Program flowchart </h2>

```mermaid
graph LR;

    s((Start))-->i{interactive mode?};

    
    i{interactive mode?}-->|yes|p("pompt");
    p("pompt")-->l("write line");
    i{interactive mode?}-->|no|l("write line");
    
    l("write line")-->e("ejecuto");
    e("ejecuto")-->i{interactive mode?};
    
    e("ejecuto")-->bi{"built-in"};
    
    
    bi{"built-in"}-->|yes|func("especific funtions");
    
    bi{"built-in"}-->|no|rt{"path ?"};
    
    rt{"path ?"}-->|si|chph("chek patch");
    chph("chek patch")-->xist{"exist path?"};
    xist{"exist path?"}-->|yes|func("especific funtions")
    
    
    com{"only comand?"}-->|yes|usph("use PATH");
    usph("use PATH")-->func("especific funtions");
    rt{"path ?"}-->|no|com{"only comand?"};

```

<h2> Format </h2>

<h3> Examples interactive mode</h3>

$ ./hsh<br>
($) /bin/ls<br>
hsh main.c shell.c<br>
($)<br>
($) exit<br>
$<br>

<h3> Examples non interactive mode</h3>


$ echo "/bin/ls" | ./hsh<br>
hsh main.c shell.c test_ls_2<br>
$<br>
$ cat test_ls_2<br>
/bin/ls<br>
/bin/ls<br>
$<br>
$ cat test_ls_2 | ./hsh<br>
hsh main.c shell.c test_ls_2<br>
hsh main.c shell.c test_ls_2<br>
$<br>

	
	
<h2>Authors</h2>

Facundo San Andrea<br>
Juan Rey
