#include "Header.hpp"

#if 0
const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] = 
{
  53ul, 97ul, 193ul, 389ul, 769ul,
  1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
  49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
  1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
  50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
  1610612741ul, 3221225473ul, 4294967291ul
};

size_t GetNextPrime(size_t capacity);

class DFInt 
{
  public:
    size_t operator()(const size_t& val) 
    {
      return val;
    }

};

class DFStr 
{
  public:
    size_t operator()(const std::string& s) 
    {
      return BKDRHash(s.c_str());
    }

  private:
    size_t BKDRHash(const char* str) 
    {
      size_t ret = 0;
      while (*str != '\0') 
      {
        ret = ret * 131 + *str;
        ++str;
      }
      return ret;
    }
};

enum Stat 
{
  EMPTY,
  EXIST,
  DELETE 
};

template<class K,class V,class KeyOfValue,class DF = DFInt>
class HashTable 
{
  struct Elem 
  {
    Elem(const Stat stat = EMPTY)
    {
      _stat = stat;
    }

    pair<K,V> _val;
    Stat _stat;   
  };

  public:
  HashTable(size_t capacity = 3)
    :_ht(capacity)
     ,size(0)
  {}

  bool Insert(const pair<K,V>& val)
  {
    _CheckCapacity();
    size_t HashAddr = HashFunc(val.first);
    while(_ht[HashAddr]._stat != EMPTY)
    {
      if(_ht[HashAddr]._stat == EXIST && _ht[HashAddr]._val == val.first)
      {
        return false;
      }
      HashAddr++;
      if(HashAddr == _ht.capacity())
      {
        HashAddr = 0;
      }
    }

    _ht[HashAddr]._val = val;
    _ht[HashAddr]._stat = EXIST;
    size++;
    return true;
  }


  private:
  void _CheckCapacity()
  {}

  size_t HashFunc(const K& key)
  {
    return key % _ht.capacity();
  }

  vector<Elem> _ht;
  size_t size;
};

int main()
{
  return 0;
}
#endif

template<size_t N>
class BitSet 
{
  public:
    BitSet()
      :_bit(N >> 3)
       ,count(0)
  {}
  
    BitSet<N> set(size_t const& pos)
    {
      if(pos >= N)
      {
        return *this;
      }

      size_t index = pos >> 3;
      size_t bit = pos % 8;
      if((_bit[index] & (1 << bit)) == 0)
      {
        _bit[index] |=  (1 << bit);
        count++;
      }
      return *this;
    }

    BitSet<N> reset(size_t const pos)
    {
      if(pos >= N || pos < 0)
      {
        return *this;
      }

      size_t index = pos >> 3;
      size_t bit = pos % 8;
      if((_bit[index] & (1 << bit)) == 1)
      {
        _bit[index] &= ~(1 << bit);
      }
      return *this;
    }

  private:
    vector<unsigned char> _bit;
    size_t count;
};





