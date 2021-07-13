Serbian-
	 Program koji simulira upis studenata u narednu nastavnu godinu.
	Svakog studenta karakteriše ime, prezime, broj indeksa (jedinstven identifikator),
	studijski program, trenutna godina studija.

	Iz reda cekanja studenti „dolaze“ na šalter studentske službe. Za svakog
	studenta se generiše pseudoslucajan broj izmeðu 0 i 1 koji predstavlja
	verovatnoæu da ce upis biti obavljen uspešno. Ukoliko je generisani broj veci
	od zadatog praga X (0 <= X <= 0.5), student obavlja upis i uklanja se iz reda po
	završetku. Na standardnom izlazu se ispisuje ime i prezime studenta i koju
	godinu je upisao. U suprotnom, student se prebacuje na kraj reda.
 
	Potrebno je najmanje implementirati sledece operacije: 
	- dohvatanje elementa iz reda 
	- stavljanje elementa u red
	- proveru da li je red prazan ili pun

English-
	A program that simulates student enrollment in the next academic year.
	Each student is characterized by name, surname, index number (unique identifier),
	study program, current year of study.

	From the waiting list, students "come" to the student service counter. For anyone
	the student generates a pseudorandom number between 0 and 1 which represents
	the probability that the enrollment will be successful. If the generated number is higher
	from the given threshold X (0 <= X <= 0.5), the student enrolls and is removed from the queue by
	completion. The standard output shows the name and surname of the student and which one
	he enrolled for a year. Otherwise, the student switches to the end of the line.
 
	The following operations must be implemented at least:
	- retrieving an element from a linked list
	- putting the element in linked list
	- check if the list is empty or full
