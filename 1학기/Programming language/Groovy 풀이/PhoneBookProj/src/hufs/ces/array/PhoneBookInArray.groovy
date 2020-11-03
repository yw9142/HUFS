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

def findLoc2(def num){
	for (def i=0; i<lastp; ++i){
		if (arrayPhoneBook[i].phoneNumber == num)
			return i;
	}
	return -1; // not found
}

def findnum(def name){
	int loc = findLoc(name);
	if (loc == -1)
	{
		println("Not found");
		return null; // not found
	}
	return arrayPhoneBook[loc];
}

def findname(def num){
	int loc = findLoc2(num);
	if (loc == -1)
	{
		println("Not found");
		return null;
	}
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
	def loc = findLoc(name);
	if (loc != -1)
		arrayPhoneBook[loc].phoneNumber = num;
	else
		println "***Error -- Name not found";
}

def listAll(){
	println "Name\tNumber";
	for (def i=0; i<lastp; ++i){
		println "${i}\t${arrayPhoneBook[i].phoneName}\t" +
				"${arrayPhoneBook[i].phoneNumber}"
	}
}

// main
incount = nameData.size(); /// array size
for (def i=0; i < incount; ++i){ /// def 동적 할당
	insert(nameData[i], numberData[i]);
}
// 과제
// 3 사람 추가
println "List All Inserted Entry";
listAll();

remove("Kim KS"); // 있는 이름
remove("Park YH"); // 없는 이름

insert("Kim CS", 5555); // 추가
insert("Park SH", 5023); // 중복된 이름
insert("PARK YH", 8045); // 추가
insert("Kang HJ", 5544); // 추가
insert("Song JH", 9999); // 추가

update("Kang JH", 5999); // 있는 이름
update("Park YH", 8045); // 없는 이름

println "Find Phone Number By Name -- Kim CS	${findnum("Kim CS").phoneNumber}"; // 이름으로 번호 찾기
println "Find Name By Phone Number -- 5555	${findname(5555).phoneName}"; // 번호로 이름 찾기
findnum("Kim CR"); // 없는 이름으로 번호 찾기
findname(1999); // 없는 번호로 이름 찾기
// insert, remove, find, update 를 에러가 생기도록 추가

println "List All Updated Entry";
listAll();
