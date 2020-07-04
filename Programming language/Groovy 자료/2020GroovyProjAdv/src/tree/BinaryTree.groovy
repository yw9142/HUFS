package tree;

class BinaryTree {
	def node
	BinaryTree left
	BinaryTree right
	def empty

	BinaryTree() {
		empty = true
	}
	BinaryTree(key, val) {
		empty = false
		node = ["key":key, "val":val]
		left = new BinaryTree()
		right = new BinaryTree()
	}
	def insert(key, val) {
		if (empty) {
			empty = false
			node = ["key":key, "val":val]
			left = new BinaryTree()
			right = new BinaryTree()
			true
		}
		if ((key <=> node["key"]) < 0)
			left.insert(key, val)
		else if ((key <=> node["key"]) > 0)
			right.insert(key, val)
		else
			false
	}
	def insert(node) {
		insert(node["key"], node["val"])
	}
	def search(key) {
		if (empty)
			null;
		if ((key <=> node["key"]) < 0)
			left.search(key)
		else if ((key <=> node["key"]) > 0)
			right.search(key)
		else
			node["val"]
	}
	def inorder() {
		if (!empty) {
			left.inorder()
			println "(${node['key']}, ${node['val']})"
			right.inorder()
		}
	}
	def inorder(clo) {
		if (!empty) {
			left.inorder(clo)
			clo(node)
			right.inorder(clo)
		}
	}
	def preorder(clo) {
		if (!empty) {
			clo(node)
			left.preorder(clo)
			right.preorder(clo)
		}
	}
	def preorder(lev, clo) {
		if (!empty) {
			clo(lev, node)
			left.preorder(lev+1, clo)
			right.preorder(lev+1, clo)
		}
	}
	def postorder(clo) {
		if (!empty) {
			left.postorder(clo)
			right.postorder(clo)
			clo(node)
		}
	}
	def clear() {
		empty = true
	}
	def size() {
		if (!empty)
			1 + left.size() + right.size()
		else
			0
	}
	def copy() {
		def cop = new BinaryTree();
		if (!empty) {
			cop.empty = false
			cop.node = node
			cop.left = left.copy()
			cop.right = right.copy()
		}
		cop
	}
	static def buildFromList(List list) {
		def tree = new BinaryTree();
		list.forEach { tree.insert(it) }
		tree
	}

	static main(args) {
		String[] nameData = ["Park SH", "Kang JH",
			"Kim KS", "Lee YH", "Kang SH","Bae JM",
			"Lee DI", "Lee BH", "Jang WH", "Chun WY"];
		int[] numberData = [5023, 5002, 5008,
			5067, 5038, 5381, 5125, 5165, 5684, 5752];

		def tree = new BinaryTree();
		for (int i=0; i < nameData.length; ++i){
			tree.insert(nameData[i], numberData[i]);
		}
		println "tree.size()=${tree.size()}"
		println("inorder print")
		tree.inorder()
		println()
		println("inorder print with closure")
		tree.inorder { println "(${it['key']}, ${it['val']})" }
		println()
		println("preorder print with closure")
		tree.preorder { println "(${it['key']}, ${it['val']})" }

		// pretty print
		println()
		println("preorder pretty print")
		def TAB_SIZE = 3
		tree.preorder (0) { lev, node ->
			if (lev!=0) {
				(1..lev*TAB_SIZE).each {
					if (it % TAB_SIZE == 1)
						print "|"
					else
						print " "
				}
			}
			println "(${node['key']}, ${node['val']})"
		}

		// Build inorder visit list
		List inorderList = []
		tree.inorder {
			inorderList.add(it)
		}
		println ""
		println "print inorder visit list"
		inorderList.forEach {
			println "(${it['key']}, ${it['val']})"
		}
	}
}
