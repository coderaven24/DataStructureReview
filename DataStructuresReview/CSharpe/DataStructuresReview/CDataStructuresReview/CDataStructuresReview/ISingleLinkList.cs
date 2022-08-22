using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CDataStructuresReview
{
    public interface ISingleLinkList<T> : 
        IDataStructureTest
    {
        void Add(T obj);

        void AddLast(T obj);

        void Clear();

        T First();

        void InsertAfter(T obj, T after);

        void InsertBefore(T obj, T before);

        bool IsEmpty();

        void Remove(T obj);

        int Size();
    }
}
