import DataStructures.*;
import DataStructures.Interfaces.IDataStructureTest;

import java.util.*;

public class Driver {

	public static void main(String[] args){

		List<IDataStructureTest> structures = new ArrayList<IDataStructureTest> ();	
	
		structures.add(new SingleLinkList());
		structures.add(new DoubleLinkList());	
		structures.add(new BinaryTree());		
		
		System.out.println("Start Data Structures Test------------------------------");		
				
		for (IDataStructureTest struct : structures) 
		{ 
			struct.test();
		}	
		
		System.out.println("Ending Data Structures Test------------------------------");				
	}

}
