package hufs.ces.list

nameData = ["Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
			"Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY"];
numberData = [5023, 5002, 5008,	5067, 5038, 5381, 5125, 5165, 5684, 5752];

arrayPhoneBook = []; // ArrayList 

def findLoc(def name){
	for (def i=0; i<arrayPhoneBook.size(); ++i){
		if (arrayPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}

Entry find(def name){
	for (Entry ent in arrayPhoneBook) {
		if (ent.phoneName == name)
			return ent;
	}
	return null;
}

def insert(def name, def number){
	if (find(name) == null){ // insert
		arrayPhoneBook.add(new Entry(name, number));
	}
	else {
		println "***Error -- Duplicated Name";
	}
}
def remove(def name){
	def loc = findLoc(name)
	if (loc != -1){ // there exist name
		arrayPhoneBook.remove(loc)
	}
	else {
		println "***Error -- Name not found";
	}
}
def update(def name, def num){
	def loc = findLoc(name)
	arrayPhoneBook[loc].phoneNumber = num
}
def listAll(){
	println "Name\tNumber";
	def i =  0
	for (Entry ent in arrayPhoneBook){
		println "${++i}\t${ent.phoneName}\t${ent.phoneNumber}"
	}
}

// main
incount = nameData.size();
for (def i=0; i < incount; ++i){
	insert(nameData[i], numberData[i]);
}
println "List All Inserted Entry";
listAll();

remove("Kim KS");
insert("Kim CS", 5555);
update("Kang JH", 5999);
println "Find Phone Number By Name -- Kim CS	${find("Kim CS").phoneNumber}";

println "List All Updated Entry";
listAll();
