# README file za temperaturu motora

Dobrodošli u moj mini projekt u kojem manipuliramo velikom količinom podataka i iz nje izvkačimo ono što nam je potrebno.
CSV file originalno sadrži malo više od 17 milijuna podataka spremljenih kao stringovi.
Mapa je kreirana čitanjem 500 000 linija CSV file-a, delimiter je "," te se prvi stupac koristi kao key, a preostala dva stupca kao par vrijednosti



**METODE**

get_top_keys(int n = 1) - metoda isprinta n broj najvećih ključeva          
get_min_keys(int n = 1) - metoda isprinta n broj najmanjih ključeva
get_max_values(int odabir = 0) - metoda koja isprinta najveći value s obzirom na vrijednost ključa, odabir u ovom slučaju služi da odaberemo 2. ili 3. stupac
get_min_values(int odabir = 0) - metoda koja isprinta najmanji value s obzirom na vrijednost ključa, odabir u ovom slučaju služi da odaberemo 2. ili 3. stupac
delete_by_key(long double i = 0) - metoda koja obriše cijeli red ukoliko nađe dani key
delete_by_value(long double i = 0) - metoda provjera da li se dana vrijednost nalazi u 2. ili 3. stupcu te obriše redak u kojem se nalazi
add_by_key(long double key, long double prvi, long double drugi) - metoda u kojoj je moguće dodati novi key te mu ujedno i pridružiti željene vrijednosti
find(long double x) - prolazi sve key-eve i traži zadani, ukoliko ga naže ispiše ga i njegovu vrijednost



**POKRETANJE PROGRAMA**

Main funkcija u programu stvara klasu Motor i popunjava ju podacima koje su pročitani iz CSV datoteke. Zatim poziva metode definirane u klasi kako bi demonstrirao njihovu funkcionalnost.
