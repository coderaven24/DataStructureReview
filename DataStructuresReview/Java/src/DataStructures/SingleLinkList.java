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
	
	public void append(Object obj) {
		head  = new Node(obj, head);
		
		if(tail == null)		
			tail = head;
		
		size++;
	}	

	public void prepend(Object obj) {
		Node tmp = new Node(obj, null);
				
		if(head != null)
			tail.next = tmp;
		else		
			head = tmp;
		
		tail = tmp;
		size++;
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

	}

	public void insertBefore(Object obj, Object before) {

	}

	public boolean isEmpty() {
		return size == 0;
	}

	public void remove(Object obj) {
		Node runner = head;
		Node prev = null;
		
		while(runner != null && runner.value != obj)
		{
			prev = runner;
			runner = runner.next;
		}
		
		if(runner != null)
		{
			if(runner== head)
				head = runner.next;
			
			else
				prev.next = runner.next;
			
			if(runner == tail)
				tail = prev;	
		}	
	}

	public int size() {
		return size;
	}

	public void test() {
		System.out.println("SingleLinkList______________________");

		System.out.println("is empty : " + isEmpty());
		System.out.println("adding letters a thru m to the list");

		append('a');
		append('b');
		append('c');
		append('d');
		append('e');
		append('f');
		append('g');
		append('h');
		append('i');
		append('j');
		append('k');
		append('n');
		append('m');

		testOutputContents();

		System.out.println("is empty : " + isEmpty());

		System.out.print("adding a 'y' to the front | ");

		prepend('y');

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