
def greet_user() {
	println("Hello!")
}
greet_user() // function overloading

def greet_user(username) {
	println("Hello, ${username} !")
}
greet_user('jesse') // function overloading

def describe_pet(animal_type, pet_name) {
	// Display information about a pet.
	println ("I have a $animal_type.")
	println("My $animal_type's name is $pet_name.")
}
describe_pet('hamster', 'harry')
describe_pet('dog', 'willie')

def get_formatted_name(first_name, last_name) {
	//Return a full name, neatly formatted.
	def full_name = "$first_name $last_name"
	return full_name
}
musician = get_formatted_name('jimi', 'hendrix')
println (musician)

def get_formatted_name(first_name, middle_name, last_name) {
	//Return a full name, neatly formatted."""
	def full_name = first_name + ' ' + middle_name + ' ' + last_name
	return full_name
}
musician = get_formatted_name('john', 'lee', 'hooker')
println (musician)

def build_person(first_name, last_name) {
	//Return a dictionary of information about a person.
	def person = ['first': first_name, 'last': last_name]
	return person
}
musician = build_person('jimi', 'hendrix')
println (musician)

def greet_users(names) {
	//Print a simple greeting to each user in the list."""
	for (name in names) {
		def msg = "Hello, $name!"
		println (msg)
	}
}
usernames = ['hannah', 'ty', 'margot']
greet_users(usernames)


unprinted_designs = ['iphone case', 'robot pendant', 'dodecahedron']
completed_models = []
//Simulate printing each design, until none are left.
//Move each design to completed_models after printing.
while (unprinted_designs) {
	current_design = unprinted_designs.remove(0)
	//Simulate creating a 3D print from the design.
	println("Printing model: $current_design")
	completed_models.add(current_design)
}
println completed_models
println unprinted_designs

def print_models(List unprinted_designs, List completed_models) {
	/*
	Simulate printing each design, until none are left.
	Move each design to completed_models after printing.
	*/
	while (unprinted_designs) {
		def current_design = unprinted_designs.remove(0)
		// Simulate creating a 3D print from the design.
		println ("Printing model: $current_design")
		completed_models.add(current_design)
	}
}
def show_completed_models(completed_models) {
	//Show all the models that were printed.
	println("The following models have been printed:")
	for (completed_model in completed_models)
		println(completed_model)
}
unpr_designs = ['iphone case', 'robot pendant', 'dodecahedron']
comp_models = []

print_models(unpr_designs, comp_models)
println unpr_designs
println comp_models
show_completed_models(comp_models)
