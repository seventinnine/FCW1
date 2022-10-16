# 1. Grammatiken – Grundbegriffe

## a)

| VT(G) = { `"DATA"`, `","`, `"/"`, `"*"`, `id`, `num`, `str`, `"+"`, `"-"`, `"("`, `")"`, `"="`, `expr` } | = 13

| VN(G) = { `DataDecl`, `DataDeclRest`, `DataNameList`, `DataValueList`, `DataName`, `DataNameList`, `DataDoList`, `DataValue`, `DataDoListRest` } | = 9

## b) 

shortest:
* `DATA id / num /`
* `DATA id / str /` 
* `DATA id / id /` 

## c)



Direkt rekursiv: 
* `DataDeclRest`: links
* `DataNameList`: rechts
* `DataValueList`: links
* `DataDoList`: zentral
* `DataDoListRest`: links

Indirekt rekursiv:
* `DataDoList` => `DataDoListRest`: zentral
* `DataDoListRest` => `DataDoList`: zentral

## d)

DataStat -> "Data" DataDecl DataDeclRest .

DataDeclRest -> ε | DataDeclRest DataDecl | DataDeclRest `","` DataDecl .

DataDecl -> DataNameList `"/"` DataValueList `"/"` .

DataNameList -> DataName | DataName `","` DataNameList .

DataName -> id | DataDoList .

DataValueList -> DataValue | DataValueList `","` DataValue .


DataValue -> OptSign num | str | id 
* | num `"*"` id 
* | num `"*"` OptSign num 
* | num `"*"` str 
* | id `"*"` id
* | id `"*"` OptSign num
* | id `"*"` str
* .

OptSign -> ε | `"+"` | `"+"` .

DataDoList -> `"("` DataDoList DataDoListRest `")"` 
* | `"("` id `"("` IdList `")"` DataDoListRest `")"`
* .
IdList -> id | IdList `","` id .

DataDoListRest -> ε 
* | DataDoListRest `","` DataDoList 
* | DataDoListRest `","` id `"("` ExprList `")"` 
* | DataDoListRest `","` id `"="` expr `","` expr
* | DataDoListRest `","` id `"="` expr `","` expr, expr
* .

ExprList -> expr | ExprList `","` expr .

EBNF ist lesbarer, da man mit weniger Alternativen durch Verwendung von `"["` und `"]"` benötigt kann und keine Rekursion mit NTs für das mehrfache Vorkommen von \[Terminal-\]Symbolen verwenden muss.

## e)

![bam](imgs/bam.PNG)

Für diesen Satz gib es nur einen Syntaxbaum, da es bei jeder Regel nur eine Alternative gibt, die zu diesem gegeben Satz führt.

# 2. Konstruktion einer Grammatik

## Regelsystem

S -> OptSign LeadingDigit MiddleDigits UnevenNaturalDigit | OptSign UnevenNaturalDigit . // man könnte auch OptSign weglassen und dafür 4 weitere Optionen im NT "S" hinzufügen

OptSign -> ε | + | - .

MiddleDigits -> ε | 0 MiddleDigits | LeadingDigit MiddleDigits .

UnevenNaturalDigit -> 1 | 3 | 5 | 7 | 9 .

LeadingDigit -> UnevenNaturalDigit | 2 | 4 | 6 | 8 .

## EBNF

S = \[ + | - \] \[ (1|2|3|4|5|6|7|8|9) { (0|1|2|3|4|5|6|7|8|9) } \] (1|3|5|7|9) . 

<div style="page-break-after: always; visibility: hidden"> 
\pagebreak 
</div>

# 3. Oo-Implementierung von Grammatiken

No changes made to existing code. I used C++20.

## a)

### main.cpp

![](imgs/main1.PNG)

<div style="page-break-after: always; visibility: hidden"> 
\pagebreak 
</div>

### Testcode:

![](imgs/test1.PNG)

### Result:

![](imgs/result1.PNG)

## b) and also c)

### main.cpp

![](imgs/main2.PNG)

<div style="page-break-after: always; visibility: hidden"> 
\pagebreak 
</div>

### Language.h

![](imgs/language_h.PNG)

<div style="page-break-after: always; visibility: hidden"> 
\pagebreak 
</div>

### Language.cpp

![](imgs/language_cpp.PNG)

### Testcode:

![](imgs/test2.PNG)

### Result:

![](imgs/result2.PNG)

Man kann erkennen, dass die länge der generieten Sätze immer gerade ist und jeder Satz gleich viele `a` wie `b` hat.

Ja kann man.
Der einfachste Satz wäre `S -> b A -> b a`, indem man die erste Alternative von `A` verwendet.
Bei der dritten Alternative vom NTSymbol `A` gibt es gleich viele TSymbole `b` wie NTSymbole `A`.
Jedes NTSymbol `A` terminiert in TSymbol `a` oder es kommt zur Ableitung in die dritten Alternative, wodurch effektiv wider ein TSymbol `a` und ein NTSymbol `A` hinzukommen.
Beim Ableiten der zweiten alternative kommt wie bei der ersten Alternative auch ein TSymbol `a` hinzu und ein neuer Satz `S`.
Wenn alle Ableitungen vor dem Ableiten von `S` durchgeführt werden, befinden sich bereits gleich viele `a` wie `b` im Satz.
Jedes vorkommende `S` muss daher auch gleich viele `a` wie `b` erzeugen.
Das gleiche gilt auch in die andere Richtung `S -> a B`, da die Regeln im NTSymbol `B` nur `b` und `A` mit `a` und `B` getauscht haben.
