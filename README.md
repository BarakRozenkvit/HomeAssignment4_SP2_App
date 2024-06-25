#### Barak10101998@gmail.com
# תכנות מערכות 2 מטלה 4 - עצים ואיטרטורים
___  
הפעלה:  `make tes,״,ָ
---
לקימפול `make tree`

לקימפול טסטים `make test`

מימוש מחלקת העץ `Tree.hpp`
-
מחלקה זו היא מסוג `Template<typename T,int n=2>` כאשר T  הם סוגי המפתחות בכל צומת וn הוא מספר הילדים המקסימלי לכל צומת, מצב הדיפולטיבי הוא 2.
שדות ומתודות פרטיים:
- מצביע לראש העץ `Node<T>* _root`
- מספר הצמתים בעץ `int _V`
- מחלקת האיטרטור הפרטית של העץ `class tree_iterator`
- אובייקט הערימת מינימום של העץ `MinHeap<T> _heap`

מתודות ציבוריות:
-	בנאי ריק המאתחל את מספר הצמתים בעץ להיות 0 ואת השורש להיות `null Tree()`
-	מפרק המוחק את ראש העץ  `~Tree()`
-	קבלת מצביע של שורש העץ `Node<T>* get_root()`
-	הוספת שורש לעץ `void add_root(Node<T> &root)`
-	הוספת ילד לצומת בעץ `void add_sub_node(Node<T>& root,Node<T>& child)`
-	הגדרת תנאים לפונקציות האופרטורים, כשאר העץ הוא בינארי תחזיר אופרטור מסוים, אחרת תחזיר אופרטור אחר:
     o	`Using iterator_pre_order`
     o	`Using iterator_post_order`
     o	`Using iterator_in_order`
-	קבלת התחלה של איטרטור פרי אורדר `iterator_pre_order begin_pre_order()`
-	קבלת סוף של איטרטור פרי אורדר `iterator_pre_order end_pre_order()`
-	קבלת התחלה של איטרטור פוסט אורדר `iterator_post_order begin_pre_order()`
-	קבלת סוף של איטרטור פוסט אורדר `iterator_post_order end_pre_order()`
-	קבלת התחלה של איטרטור אין אורדר `iterator_in_order begin_pre_order()`
-	קבלת סוף של איטרטור אין אורדר `iterator_in_order end_pre_order()`
-	קבלת התחלה של איטרטור `bfs iterator_bfs<T> begin_bfs_scan()`
-	קבלת סוף של איטרטור `bfs iterator_bfs<T> end_bfs_scan()`
-	קבלת התחלה של איטרטור `dfs iterator_dfs<T> begin_dfs_scan()`
-	קבלת סוף של איטרטור `dfs iterator_dfs<T> end_dfs_scan()`
-	קבלת התחלה של איטרטור עץ `tree_iterator begin()`
-	קבלת סוף של איטרטור העץ `tree_iterator() end()`
-	קבלת איטרטור התחלה וסוף של הערימת מינימום של העץ `pair<heap_iterator<T>,heap_iterator<T>> myHeap()`

מימוש מחלקת הצומת `Node.hpp`
-
מחלקה זו היא מסוג `Template<typename T >` כאשר T  הם סוגי המפתחות בכל צומת
שדות ומתודות פרטיים:
- המידע שמחזיק צומת בתוכו `T _data`
- וקטור הילדים שלו שהם מצביעים לצמתים אחרים `vector<Node<T>*> _childs`

מתודות ציבוריות:
- בנאי המקבל אובייקט ומתאחל את המידע בצומת ואת הוקטור להיות ריק `Node(T data)`
- בנאי מעתיק המקבל צומת ועושה לה העתקה עמוקה `Node(Node<T>& other)`
- בנאי מפרק המוחק את כל הילדים בוקטור שהוקצו באופן דינאמי `Node()~`
- הוספת ילד לצומת `add_child(Node<T>& node)`
- קבלת המידע בצומת `get_value()`
- קבלת המצביע לילד הכי שמאלי `Node<T>* getLeft()`
- קבלת המצביע לילד הכי ימני `Node<T>* getRight()`
- קבלת וקטור הילדים של הצומת `vector<Node<T>*> getChilds()`
- `אופרטור השוואה בין צמתים bool operator==(Node<T>* node)`
- אופרטור השמה להעתקה עמוקה של צמתים `Node<T>& operator=(Node<T>& other)`

מימוש קובץ איטרטורים `Iterator.hpp`
-
למחלקה זאת מספר מחלקות שכל מחלקה מייצגת איטרטור המממש דרך אחרת לעבור על העץ. לכל מחלקה אותם מתודות אותם היא מממשת באופן שונה, מחלקות אלה זו הן מסוג `Template<typename T >` כאשר T  הם סוגי המפתחות בכל צומת

שדות פרטיים:
- מבנה נתונים המחזיק את המצביעים של הצמתים בעץ stack/queue/vector
- משתנה עזר שמצביע על צומת מסוימת בעץ

מתודות ציבוריות:
- בנאי המאתחל את מבנה הנתונים של האיטרטור והמשתנים `iterator_*(Node<T> ptr==null)`
- אופטור קידום של האיטרטור המחזיר את עצמו `iterator_* operator++()`
- אופרטור חץ הנותן גישה למתודות של הצומת הנוכחית בעץ `Node<T>* operator->()`
- אופרטור כוכבית המחזיר מצביע לצומת נוכחית בעץ `Node<T>* operator*()`
- אופרטור שיוון ושונה בין איטרטורים `bool operator !=/==(const iterator_*& other) const`

מימוש מחלקת הערימת מינימום Heap.hpp
- 
מחלקה זו היא מסוג `Template<typename T >` כאשר T  הם סוגי המפתחות בכל צומת

שדות ומתודות פרטיים:
- וקטור מסוג T המייצג את הערימה `vector<T> _array`
- מתודה שעושה Heapify לערימה מאינדקס מסוים `void minHeapify(vector<T>& heapArray, int i)`
- מתודה שמסדרת ערימה בוקטור הערימה `void BuildMinHeap()`

מתודות ציבוריות:
-  בנאי המקבל איטרטור התחלה bfs ואיטרטור סוף bfs של העץ ובונה ערימה `MinHeap(iterator_bfs<T> begin,iterator_bfs<T> end)`
- מתודה מקבלת את הערימה `vector<T>& getHeap()`

מימוש המחלקה `TreeView.hpp` לציור העץ בGUI
-

מחלקה זאת יורשת ממחלקת QWidget של ספריית הGUI של QT.

שדות פרטיים:
- וקטור של אובייקט QRect שכל אחד מהם מייצג צומת לציור `vector<QRect> _circles`
- מפה של מחרוזות ל QRect שממפה מחרוזות לצומת בציור `map<string,QRect> _texts`
- וקטור של זוג QPoint המייצג צלעות בעץ לציור `vector<pair<QPoint,QPoint>> _lines`

מתודות ציבוריות ומוגנות:
- הוספת צומת קורדינאטות הצמתים לציור לוקטור `void addNode(int x,int y)`
- הוספת טקסט וקורדינאטות לציור למפה `void addText(int x,int y,string data)`
- הוספת קורדינאטות הצלע לציור לוקטור `addLine(int xOrigin, int yOrigin, int xDest, int yDest(`
- מתודה המוסיפה את קורדינאטות הצומת, הטקסט והצלע שלה ושל כל ילדיה `template <typename T> void draw(Node<T>* current, int dist,int x,int y)`
- אופרטור הדפסה המדפיס את העץ לGUI `template <typename T,int n> friend TreeView& operator<<(TreeView& treeview,Tree<T,n>& tree)`
- מתודה מוגנת המופעלת כאשר קיימת פקודה לציור, ותפקידה לצייר במסך

מימוש המחלקה Complex.hpp
- 
שדות פרטיים:
- מספר אמיתי `int _real`
- מספר דמיוני `int _imag`

מתודות ציבוריות:
- בנאי המאתחל את המשתנים `Complex(int real, int imag)`
- אופרטור השוואה `bool operator==(Complex& comp)`
- אופרטור גדול `bool operator<(Complex& other)`
- פונקצייה המחזירה מחרוזת של האובייקט `friend string to_string(const Complex& comp)`
- פונקציית הדפסה `friend ostream& operator<<(ostream& out,Complex& comp)`


