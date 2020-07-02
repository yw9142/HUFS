package hufs.ces.array

MAX_ENTRY = 100;

nameData = ["Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
			"Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY"];
numberData = [5023, 5002, 5008,	5067, 5038, 5381, 5125, 5165, 5684, 5752];

arrayPhoneBook = new Entry[MAX_ENTRY];
lastp = 0;

def findLoc(def name){
	for (def i=0; i<lastp; ++i){
		if (arrayPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}

def find(def name){
	int loc = findLoc(name);
	if (loc == -1)
		return null; // not found
	return arrayPhoneBook[loc];
}

def insert(def name, def number){
	def loc = findLoc(name);
	if (loc == -1){ // insert
		if (lastp >= MAX_ENTRY){
			println "***Error -- PhoneBook Overflow";
		}
		else {
			arrayPhoneBook[lastp] = new Entry(name, number);
			lastp++;
		}
	}
	else {
		println "***Error -- Duplicated Name";
	}
}
def remove(def name){
	def loc = findLoc(name);
	if (loc != -1){ // there exist name
		// remove array entry at loc
		for (def i=loc+1; i<lastp; ++i){
			arrayPhoneBook[i-1] = arrayPhoneBook[i]
		}
		lastp--;
	}
	else {
		println "***Error -- Name not found";
	}
}
def update(def name, def num){
	remove(name);
	insert(name, num);
}
def listAll(){
	println "Name\tNumber";
	for (def i=0; i<lastp; ++i){
		println "${i}\t${arrayPhoneBook[i].phoneName}\t" +
				"${arrayPhoneBook[i].phoneNumber}"
	}
}

// main
incount = nameData.size();
for (def i=0; i < incount; ++i){
	insert(nameData[i], numberData[i]);
}
// 과제
// 3 사람 추가
println "List All Inserted Entry";
listAll();

remove("Kim KS");
insert("Kim CS", 5555);
update("Kang JH", 5999);
println "Find Phone Number By Name -- Kim CS	${find("Kim CS").phoneNumber}";
// insert, remove, find, update 를 에러가 생기도록 추가

println "List All Updated Entry";
listAll();
