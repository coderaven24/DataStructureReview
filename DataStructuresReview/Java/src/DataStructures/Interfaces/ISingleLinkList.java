package DataStructures.Interfaces;

public interface ISingleLinkList extends IDataStructureTest {
	public void add(Object obj);

	public void addLast(Object obj);

	public void clear();

	public Object first();

	public void insertAfter(Object obj, Object after);

	public void insertBefore(Object obj, Object before);

	public boolean isEmpty();

	public void remove(Object obj);

	public int size();
}
