package DataStructures;

import DataStructures.Interfaces.ISingleLinkList;

public class SingleLinkList implements ISingleLinkList {

	private class Node {
		private Node next = null;
		private Object value = null;

		public Node(Object obj, Node right) {
			value = obj;
			next = right;
		}

		public Object getValue() {
			return value;
		}
	}

	private Node head = null;
	private Node tail = null;	

	private int size = 0;

	public void add(Object obj) {
		Node tmp = new Node(obj, null);
				
		if(head != null)
			tail.next = tmp;
		else		
			head = tmp;
		
		tail = tmp;
		size++;
	}

	public void addLast(Object obj) {
	/*	if (head != null) {
			Node runner = head;

			while (runner.next != null)
				runner = runner.next;

			runner.next = new Node(obj, null);
			size++;
		} else {
			head = new Node(obj, head);
			size++;
		}*/
	}

	public void clear() {
		size = 0;
		head = null;
		tail = null;		
	}

	public Object first() {
		return head.value;
	}

	public void insertAfter(Object obj, Object after) {
		/*Node runner = head;

		while (runner != null) {
			if (after == runner.getValue()) {
				runner.next = new Node(obj, runner.next);
				size++;
				return;
			}

			runner = runner.next;
		}*/
	}

	public void insertBefore(Object obj, Object before) {
	/*	Node runner = head;
		Node previous = null;

		while (runner != null) {
			if (before == runner.getValue()) {

				if (previous != null)
					previous.next = new Node(obj, previous.next);

				else
					head = new Node(obj, head);

				++size;
				return;
			}

			previous = runner;
			runner = runner.next;
		}*/
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public void remove(Object obj) {
	/*	Node runner = head;
		Node previous = null;

		while (runner != null) {

			if (obj == runner.getValue()) {
				if (previous == null)
					head = runner.next;

				else
					previous.next = runner.next;

				--size;
				return;
			}

			previous = runner;
			runner = runner.next;
		}*/
	}

	public int size() {
		return size;
	}

	@Override
	public void test() {
		System.out.println("SingleLinkList______________________");

		System.out.println("is empty : " + isEmpty());
		System.out.println("adding letters a thru m to the list");

		add('a');
		add('b');
		add('c');
		add('d');
		add('e');
		add('f');
		add('g');
		add('h');
		add('i');
		add('j');
		add('k');
		add('n');
		add('m');

		testOutputContents();

		System.out.println("is empty : " + isEmpty());

		System.out.print("adding a 'y' to the end | ");

		addLast('y');

		testOutputContents();

		System.out.print("removing e | ");

		remove('e');

		testOutputContents();

		System.out.print("removing m | ");

		remove('m');

		testOutputContents();

		System.out.print("adding z before f | ");

		insertBefore('z', 'f');

		testOutputContents();

		System.out.print("adding q after z | ");

		insertAfter('q', 'z');

		testOutputContents();

		System.out.println("SingleLinkList______________________");

	}

	private void testOutputContents() {
		System.out.print("count:" + size());

		Node runner = head;

		System.out.print(" contents:");

		while (runner != null) {
			System.out.print(runner.getValue() + " ");

			runner = runner.next;
		}

		System.out.println(" ");
	}
}