#ifndef ABR_H_
#define ABR_H_

#include <stdbool.h>
#include "../Sylphon/Sylphon.h"
/**
 * @file ABR.h
 * @struct ABR  
 *
 * @author     Drieu La Rochelle Loic && Le Gal Valentin
 * @date       2018
 * ---------------------------
 */

typedef struct _ABR ABR;
struct _ABR {
  Sylphon* racine;
	ABR* ABRright;
	ABR* ABRleft;
};

/**
 * @param a This is a Sylphon pointer as a root.
 * @return point This is a pointer to a tree.
 * @note It creates a tree without other underlying trees.
 **/
ABR* create_leaf(Sylphon* a);

/**
 * @param a This is a generic pointer as a root.
 * @param right This is a pointer to a right tree.
 * @param left This is a pointer to a left tree.
 * @return create a tree with : param a ,param right, param left.
 * 
 **/

ABR* create_ABR(Sylphon* a, ABR* right, ABR* left);

/**
*@param a This is a pointer as a tree.
*@return boolean false or true 
*@note    It checks if "a" is a leaf of the tree
*/ 
bool is_leaf(ABR* a);

/**
 * @param a @type ABR* is a pointer as a tree
 * @param x @type Sylphon* is Sylphon pointer as a root
 * @return void
 **/
void setRoot(ABR* a, Sylphon* x);

/**
 * @param a is a pointer as a tree
 * @param x is Sylphon pointer as a root
 * @note add a new value from pointeur @val(x) to tree @val(a) 
 **/
ABR* insert(ABR* a, Sylphon* x);
/**
 * @param a is a pointer as a tree
 * @return void
 * @note show a tree that is built with @val(a)
 **/
void show(ABR* a);

/**
 * @param a is a pointer as a tree
 * @return void
 * @note delete the tree pointer a that is present in the main tree 
 **/
void delete_ABR(ABR* a);
/**
 * @param a is a tree
 * 
 * @param x is a is Sylphon pointer as a root
 * 
 * @return a tree
 **/
ABR* trouve(ABR* a,Sylphon* x);

#endif  // \struct ABR_H_
