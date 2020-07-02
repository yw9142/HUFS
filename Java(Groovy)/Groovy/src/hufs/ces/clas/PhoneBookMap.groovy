package hufs.ces.clas

class PhoneBookMap implements IPhoneBook {

    private Map<String, Integer> phoneBookMap;

    PhoneBookMap() {
        phoneBookMap = [:];
        println "phoneBookMap Class = ${phoneBookMap.getClass()}"
    }

    @Override
    public int find(String name) {
        Integer pnumber = phoneBookMap[name];
        if (pnumber != null) {
            return pnumber;
        } else {
            println("Not found");
            return -1;
        }
    }

    @Override
    public String find(int number) {
        String pname = phoneBookMap.find { it.value == number }?.key
        if (pname != null) {
            return pname;
        } else {
            println("Not found");
            return -1;
        }
    }

    @Override
    public boolean insert(String name, int number) {
        if (find(name) == -1) { // insert
            //phoneBookMap.put(name, number); // Java style
            phoneBookMap[name] = number; // Groovy style
            return true;
        } else {
            return false;
        }
    }

    @Override
    /*
    public boolean update(String name, int number) {
        if (remove(name)) {
            insert(name, number);
            return true;
        } else {
            return false;
        }
    }
    */
    public boolean update(String name, int number) {
        if (find(name) != -1) { // update
            //phoneBookMap.put(name, number); // Java style
            phoneBookMap[name] = number; // Groovy style
            return true;
        } else {
            return false;
        }
    }

    @Override
    public boolean remove(String name) {
        if (find(name) != -1) { // remove
            phoneBookMap.remove(name);
            return true;
        } else {
            return false;
        }
    }

    @Override
    public void listAll() {
        println "Name\tNumber";
        phoneBookMap.each { pname, pnumber -> println "${pname}\t${pnumber}"
        }
    }
}
