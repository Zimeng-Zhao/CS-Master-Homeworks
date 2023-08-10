package FinalExam;


public class LL<E> {

	private class Node<E>{
		E val;
		Node<E> next;
		
		public Node(E val) {
			this.val = val;
			this.next = null;
		}
		
		public Node(E val, Node<E> next) {
			this.val = val;
			this.next = next;
		}
	}
		
		public Node<E> head;
		public Node<E> tail;
		public int len;
		
		//constructor:creates an empty linked list
		public LL(){
			head = null;
			tail = null;
			len = 0;
		}
		
		public void append(E val) {
			Node<E> node = new Node<E>(val);
			if(head == null) {
				head = node;
				tail = node;
				len++;
			}
			else {
				tail.next = node;
				tail = node;
				len++;
			}

		}
		
		public void prepend(E val) {//zhuyi
			Node<E> node = new Node<E>(val);
			if(head == null) {
				head = node;
				tail = node;
				len++;
			}
			else{
				node.next = head;
				head = node;
				len++;
			}

		}
		
		public void deleteEnd() {
			if(len == 0) {
				System.out.println("Empty List");
				return;
			}
			else if(len == 1) {
				System.out.println("B[0] = " + head.val);
				head = null;
				len--;
			}
			else {
				Node<E> curr = head;
				Node<E> prev = null;
				while(curr.next != null) {
					prev = curr;
					curr = curr.next;
				}
				System.out.println("B[" + (len - 1) + "] = " + prev.next.val);
				prev.next = null;
				len--;

			}

	}
		
		public void deleteStart() {
			if(len == 0) {
				System.out.println("Empty List");
				return;
			}
			else if(len == 1) {
				head = null;
				len--;
			}
			else{
				head = head.next;
				len--;
			}
		}
		
		public void delete(E val) {
			Node<E> curr = head;
			Node<E> prev = null;
			if(head == null) {
				return;
			}
			if(head.val == val) {
				head = head.next;
				return;
			}
			while(curr != null) {
				if(!curr.val.equals(val)) {
					prev = curr;
					curr = curr.next;
				}
				else {
					break;
				}
			}
			if(curr == null) {
				System.out.println("The item doen't in the list");
				return;
			}
			else {
				prev.next = curr.next;
				len--;
			}
		}
		
		public void deleteAll(E val) {
			Node<E> curr = head.next;
			Node<E> prev = head;
			
			if(head == null) {
				return;
			}
			while(curr != null) {
				if(!curr.val.equals(val)) {
					prev = curr;
					curr = curr.next;
				}
				else {
					len--;
					prev.next = curr.next;
					curr = curr.next;
				}
			}
			
		}
			
			
			
		
		public int getLen() {
			return len;
		}
		
		public void sort() {
			Node<E> curr = head;
			Node<E> currNext = curr.next;
			Node<E> temp = new Node<E>(null);
			while (curr != null) {
				while(currNext != null) {
					if(((String)curr.val).compareTo((String)currNext.val)> 0){
						temp.val = curr.val;
						curr.val = currNext.val;
						currNext.val = temp.val;
					}
					currNext = currNext.next;
				}
				curr = curr.next;	
			}
			//System.out.println(head + "");
			return;
		}
		
		public void reverse() {
			if(head == null) {
				System.out.println("Empty list");
				return;
			}
			if(head != null && head.next == null) {
				System.out.println(head + "");
			}
			
			Node<E> curr = head.next;
			head.next = null;
			while(curr != null) {
				Node<E> currNext = curr.next;
				curr.next = head;
				head = curr;
				curr = currNext;
			}
			return;
		}

	
		public void show(String[]A, LL<String> B) {
			Node<E> curr = head;
			int count = 0;
			if(head == null) {
				System.out.println("Empty List");
				return;
			}
			while(curr != null) {
				System.out.print("A[" + count + "] = " + A[count] + ",");
				System.out.println( "B[" + count + "] = " + curr.val + " ");
				curr = curr.next;
				count++;
				}
			System.out.println();
		}
		
		public void show() {
			Node<E> curr = head;
			int count = 0;
			if(head == null) {
				System.out.println("Empty List");
				return;
			}
			while(curr != null) {
				System.out.println( "B[" + count + "] = " + curr.val + " ");
				curr = curr.next;
				count++;
				}
			System.out.println();
		}
		
		
		
		public void display() {
			Node<E> curr = head;
			if(head == null) {
				System.out.println("Empty List");
				return;
			}
			while(curr != null) {
				System.out.print(curr.val + " ");
				curr = curr.next;
				}
			System.out.println();
		}
		
		
		public static void main(String[] args) {
			String[]A = {"s00", "4s1", "41s", "s31", "12s", "s14", "s23", "s42"};
			
			  LL<String> B = new LL<String>();
			  for(int i = 0;i < A.length; i++)
			  {
			   B.append(A[i]);
			  }

			  B.show(A,B);	 
		      System.out.println(B.getLen());
			  
			  B.reverse();
			  for(int i = B.len -1;i >= 0; i--){
				   B.deleteEnd();
			  }

			  
//			  B.display();
//			  B.deleteStart();
//			  B.display();
//			  B.deleteEnd();
//			  B.display();			
//			  myll.append("00r");
//			  myll.display();
//			  myll.prepend("985");
//			  myll.display();			  
//			  myll.delete("s00");
//			  myll.display();
//			  myll.append("00r");
//			  myll.display();
//			  myll.deleteAll("00r");
//			  myll.display();
//			  myll.sort();
//			  myll.display();
//		      myll.reverse();
//		      myll.display();
//		      System.out.println(myll.getLen());

		      

		}

}
