package hufs.ces.clas

class PhoneBookPolyTest {

    static void testPhoneBook(IPhoneBook pbook) {

        println "***Test ${pbook.class} PhoneBook***";

        String[] nameData = ["Park SH", "Kang JH",
                             "Kim KS", "Lee YH", "Kang SH", "Bae JM",
                             "Lee DI", "Lee BH", "Jang WH", "Chun WY"];
        int[] numberData = [5023, 5002, 5008,
                            5067, 5038, 5381, 5125, 5165, 5684, 5752];

        for (int i = 0; i < nameData.length; ++i) {
            pbook.insert(nameData[i], numberData[i]);
        }
        println "List All Inserted Entry";
        pbook.listAll();

        if (!pbook.insert(nameData[9], numberData[9])) {
            println "***Error in Insert -- ${nameData[9]} ***";
        };

        if (!pbook.remove("Kim KS")) { // 있는 이름
            println "***Error in Remove -- Kim KS ***";
        };

        if (!pbook.remove("Park YH")) { // 없는 이름
            println "***Error in Remove -- Park YH ***";
        };

        if (!pbook.insert("Kim CS", 5555)) { // 추가
            println "***Error in Insert -- Kim CS ***";
        };

        if (!pbook.insert("Park SH", 5023)) { // 중복된 이름
            println "***Error in Insert -- Park SH ***";
        };

        if (!pbook.insert("PARK YH", 8045)) { // 추가
            println "***Error in Insert -- Kim CS ***";
        };

        if (!pbook.update("Kang JH", 5999)) { // 있는 이름
            println "***Error in Update -- Kang JH ***";
        };

        if (!pbook.update("Park YH", 8045)) { // 없는 이름
            println "***Error in Update -- Park YH ***";
        };

        println "Find Phone Number By Name -- Kim CS	${pbook.find('Kim CS')}";
        println "Find Name By Phone Number -- 5555	${pbook.find(5555)}";

        pbook.find("Kim CR") // 없는 이름으로 번호 찾기
        pbook.find(1999) // 없는 번호로 이름 찾기

        println "***List All Updated Entry";
        pbook.listAll();
    }

    static main(args) {

        testPhoneBook(new PhoneBookArray());
        println("\n")
        testPhoneBook(new PhoneBookList());
        println("\n")
        testPhoneBook(new PhoneBookMap());
        println("\n")
    }

}
