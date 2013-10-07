Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls   s/call   s/call  name    
 40.78      1.81     1.81  1314424     0.00     0.00  LinkedList<Vertex>::end()
 31.99      3.23     1.42 1029585540     0.00     0.00  LinkedListNode<Vertex>::getNext()
 12.17      3.77     0.54 295504079     0.00     0.00  LinkedListNode<Edge>::getNext()
 11.72      4.29     0.52   337673     0.00     0.00  LinkedList<Edge>::end()
  0.45      4.31     0.02  1301520     0.00     0.00  Iterator<Vertex>::operator++()
  0.45      4.33     0.02  1256769     0.00     0.00  Vertex::operator==(Vertex)
  0.45      4.35     0.02   716354     0.00     0.00  Set<Vertex>::end()
  0.23      4.36     0.01  5490798     0.00     0.00  Vertex::~Vertex()
  0.23      4.37     0.01  3954454     0.00     0.00  Vertex::getName()
  0.23      4.38     0.01  1981482     0.00     0.00  Vertex::operator=(Vertex)
  0.23      4.39     0.01  1322331     0.00     0.00  Iterator<Vertex>::Iterator(LinkedListNode<Vertex>*)
  0.23      4.40     0.01  1309004     0.00     0.00  Iterator<Vertex>::operator!=(Iterator<Vertex>)
  0.23      4.41     0.01  1303453     0.00     0.00  LinkedListNode<Vertex>::getData()
  0.23      4.42     0.01   124750     0.00     0.00  Edge::operator==(Edge)
  0.23      4.43     0.01      430     0.00     0.00  LinkedListNode<Vertex>::~LinkedListNode()
  0.23      4.44     0.01                             Vertex::setHeuristic(float)
  0.00      4.44     0.00  3514512     0.00     0.00  Vertex::Vertex(Vertex const&)
  0.00      4.44     0.00  1985897     0.00     0.00  Vertex::getHeuristic()
  0.00      4.44     0.00  1980019     0.00     0.00  Vertex::Vertex()
  0.00      4.44     0.00  1972120     0.00     0.00  __gnu_cxx::__enable_if<std::__is_char<char>::__value, bool>::__type std::operator==<char>(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  0.00      4.44     0.00  1327751     0.00     0.00  Iterator<Vertex>::~Iterator()
  0.00      4.44     0.00  1303023     0.00     0.00  Iterator<Vertex>::getData()
  0.00      4.44     0.00  1022992     0.00     0.00  std::char_traits<char>::compare(char const*, char const*, unsigned long)
  0.00      4.44     0.00   463500     0.00     0.00  Edge::~Edge()
  0.00      4.44     0.00   339096     0.00     0.00  Iterator<Edge>::~Iterator()
  0.00      4.44     0.00   338596     0.00     0.00  Iterator<Edge>::Iterator(LinkedListNode<Edge>*)
  0.00      4.44     0.00   337173     0.00     0.00  Iterator<Edge>::operator!=(Iterator<Edge>)
  0.00      4.44     0.00   337000     0.00     0.00  Edge::getVertex2()
  0.00      4.44     0.00   336672     0.00     0.00  Edge::getVertex1()
  0.00      4.44     0.00   336250     0.00     0.00  LinkedListNode<Edge>::getData()
  0.00      4.44     0.00   336250     0.00     0.00  Edge::Edge()
  0.00      4.44     0.00   336250     0.00     0.00  Edge::operator=(Edge const&)
  0.00      4.44     0.00   336250     0.00     0.00  Iterator<Edge>::getData()
  0.00      4.44     0.00   336250     0.00     0.00  Iterator<Edge>::operator++()
  0.00      4.44     0.00   211923     0.00     0.00  Set<Edge>::end()
  0.00      4.44     0.00   127250     0.00     0.00  Edge::Edge(Edge const&)
  0.00      4.44     0.00     7907     0.00     0.00  LinkedList<Vertex>::begin()
  0.00      4.44     0.00     7066     0.00     0.00  Iterator<Vertex>::operator=(Iterator<Vertex> const&)
  0.00      4.44     0.00     5420     0.00     0.00  Set<Vertex>::find(Vertex)
  0.00      4.44     0.00     5420     0.00     0.00  Pair<Iterator<Vertex>, bool>::Pair()
  0.00      4.44     0.00     5420     0.00     0.00  Pair<Iterator<Vertex>, bool>::~Pair()
  0.00      4.44     0.00     5420     0.00     0.00  Iterator<Vertex>::Iterator()
  0.00      4.44     0.00     3942     0.00     0.00  Set<Vertex>::insert(Vertex)
  0.00      4.44     0.00     3664     0.00     0.00  LinkedList<Vertex>::pushFront(Vertex)
  0.00      4.44     0.00     3664     0.00     0.00  LinkedListNode<Vertex>::LinkedListNode(Vertex)
  0.00      4.44     0.00     3022     0.00     0.00  LinkedListNode<Vertex>::setNext(LinkedListNode<Vertex>*)
  0.00      4.44     0.00     2278     0.00     0.00  LinkedList<Vertex>::~LinkedList()
  0.00      4.44     0.00     2276     0.00     0.00  Set<Vertex>::~Set()
  0.00      4.44     0.00     1427     0.00     0.00  Set<Vertex>::begin()
  0.00      4.44     0.00     1427     0.00     0.00  Pair<Vertex, bool>::Pair()
  0.00      4.44     0.00     1427     0.00     0.00  Pair<Vertex, bool>::~Pair()
  0.00      4.44     0.00     1426     0.00     0.00  Set<Vertex>::Set(Set<Vertex> const&)
  0.00      4.44     0.00     1002     0.00     0.00  Graph::findVertexByName(Set<Vertex>, std::string)
  0.00      4.44     0.00     1001     0.00     0.00  std::operator|(std::_Ios_Openmode, std::_Ios_Openmode)
  0.00      4.44     0.00     1000     0.00     0.00  Graph::addVertex(Vertex)
  0.00      4.44     0.00      923     0.00     0.00  LinkedList<Edge>::begin()
  0.00      4.44     0.00      852     0.00     0.00  LinkedList<Vertex>::LinkedList()
  0.00      4.44     0.00      850     0.00     0.00  Set<Vertex>::Set()
  0.00      4.44     0.00      653     0.00     0.00  LinkedList<Vertex>::noElements()
  0.00      4.44     0.00      540     0.00     0.00  Vertex::operator<(Vertex)
  0.00      4.44     0.00      501     0.00     0.00  Vertex::Vertex(std::string, float)
  0.00      4.44     0.00      500     0.00     0.00  LinkedList<Edge>::pushFront(Edge)
  0.00      4.44     0.00      500     0.00     0.00  LinkedListNode<Edge>::LinkedListNode(Edge)
  0.00      4.44     0.00      500     0.00     0.00  Set<Edge>::find(Edge)
  0.00      4.44     0.00      500     0.00     0.00  Set<Edge>::insert(Edge)
  0.00      4.44     0.00      500     0.00     0.00  Edge::Edge(Vertex, Vertex, float)
  0.00      4.44     0.00      500     0.00     0.00  Pair<Vertex, bool>::operator=(Pair<Vertex, bool> const&)
  0.00      4.44     0.00      500     0.00     0.00  Pair<Iterator<Edge>, bool>::Pair()
  0.00      4.44     0.00      500     0.00     0.00  Pair<Iterator<Edge>, bool>::~Pair()
  0.00      4.44     0.00      500     0.00     0.00  Graph::addEdge(Vertex, Vertex, float)
  0.00      4.44     0.00      500     0.00     0.00  Iterator<Edge>::Iterator()
  0.00      4.44     0.00      500     0.00     0.00  Iterator<Edge>::operator=(Iterator<Edge> const&)
  0.00      4.44     0.00      499     0.00     0.00  LinkedListNode<Edge>::setNext(LinkedListNode<Edge>*)
  0.00      4.44     0.00      430     0.00     0.00  LinkedList<Vertex>::popNodeFront()
  0.00      4.44     0.00      430     0.00     0.00  LinkedList<Vertex>::popFront()
  0.00      4.44     0.00      430     0.00     0.00  Stack<Vertex>::pop()
  0.00      4.44     0.00      430     0.00     0.00  Stack<Vertex>::push(Vertex)
  0.00      4.44     0.00      430     0.00     0.00  Vertex::~Vertex()
  0.00      4.44     0.00      425     0.00     0.00  Graph::findVertexByName(std::string)
  0.00      4.44     0.00      424     0.00     0.00  Set<Vertex>::operator=(Set<Vertex> const&)
  0.00      4.44     0.00      424     0.00     0.00  Vertex::operator!=(Vertex)
  0.00      4.44     0.00      424     0.00     0.00  bool std::operator!=<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  0.00      4.44     0.00      423     0.00     0.00  Set<Edge>::begin()
  0.00      4.44     0.00      423     0.00     0.00  Set<Vertex>::size()
  0.00      4.44     0.00      423     0.00     0.00  Set<Vertex>::operator-(Set<Vertex>)
  0.00      4.44     0.00      423     0.00     0.00  Graph::neighbours(std::string)
  0.00      4.44     0.00      423     0.00     0.00  bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*)
  0.00      4.44     0.00      423     0.00     0.00  bool std::operator!=<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*)
  0.00      4.44     0.00      230     0.00     0.00  Stack<Vertex>::size()
  0.00      4.44     0.00      214     0.00     0.00  Set<Vertex>::smallest()
  0.00      4.44     0.00      209     0.00     0.00  Stack<Vertex>::peak()
  0.00      4.44     0.00        3     0.00     0.00  LinkedList<Edge>::~LinkedList()
  0.00      4.44     0.00        3     0.00     0.00  Set<Edge>::~Set()
  0.00      4.44     0.00        3     0.00     0.00  Graph::~Graph()
  0.00      4.44     0.00        2     0.00     0.00  LinkedList<Edge>::LinkedList()
  0.00      4.44     0.00        2     0.00     0.00  Set<Edge>::Set()
  0.00      4.44     0.00        2     0.00     0.00  Graph::contains(std::string)
  0.00      4.44     0.00        2     0.00     0.00  Graph::Graph()
  0.00      4.44     0.00        2     0.00     0.00  Stack<Vertex>::Stack()
  0.00      4.44     0.00        2     0.00     0.00  Stack<Vertex>::~Stack()
  0.00      4.44     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN12GreedySearchC2Ev
  0.00      4.44     0.00        1     0.00     0.00  _GLOBAL__sub_I__ZN5GraphC2Ev
  0.00      4.44     0.00        1     0.00     0.00  _GLOBAL__sub_I_debug
  0.00      4.44     0.00        1     0.00     0.00  __static_initialization_and_destruction_0(int, int)
  0.00      4.44     0.00        1     0.00     0.00  __static_initialization_and_destruction_0(int, int)
  0.00      4.44     0.00        1     0.00     0.00  __static_initialization_and_destruction_0(int, int)
  0.00      4.44     0.00        1     0.00     2.33  GreedySearch::search(std::string, std::string)
  0.00      4.44     0.00        1     0.00     0.00  GreedySearch::setGraph(Graph)
  0.00      4.44     0.00        1     0.00     0.00  GreedySearch::GreedySearch()
  0.00      4.44     0.00        1     0.00     0.00  GreedySearch::~GreedySearch()
  0.00      4.44     0.00        1     0.00     0.00  Set<Edge>::Set(Set<Edge> const&)
  0.00      4.44     0.00        1     0.00     0.00  Set<Edge>::operator=(Set<Edge> const&)
  0.00      4.44     0.00        1     0.00     2.10  Graph::createGraph(char const*, char const*)
  0.00      4.44     0.00        1     0.00     0.14  Graph::loadHeuristics(std::basic_ifstream<char, std::char_traits<char> >&)
  0.00      4.44     0.00        1     0.00     0.00  Graph::Graph(Graph const&)
  0.00      4.44     0.00        1     0.00     0.00  Graph::operator=(Graph const&)

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.
 
 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this 
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.
