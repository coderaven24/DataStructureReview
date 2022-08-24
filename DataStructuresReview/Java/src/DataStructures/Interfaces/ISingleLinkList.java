package DataStructures.Interfaces;

public interface ISingleLinkList extends IDataStructureTest {
	public void prepend(Object obj);

	public void append(Object obj);

	public void clear();

	public Object first();
	
	public Object last();	

	public void insertAfter(Object obj, Object after);

	public void insertBefore(Object obj, Object before);

	public boolean isEmpty();

	public void remove(Object obj);

	public int size();
}
