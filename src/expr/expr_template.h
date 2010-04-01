/*********************                                                        */
/** expr_template.h
 ** Original author: dejan
 ** Major contributors: mdeters
 ** Minor contributors (to current version): cconway, taking
 ** This file is part of the CVC4 prototype.
 ** Copyright (c) 2009, 2010  The Analysis of Computer Systems Group (ACSys)
 ** Courant Institute of Mathematical Sciences
 ** New York University
 ** See the file COPYING in the top-level source directory for licensing
 ** information.
 **
 ** Public-facing expression interface.
 **/

#include "cvc4_public.h"

// circular dependency: force expr_manager.h first
#include "expr/expr_manager.h"

#ifndef __CVC4__EXPR_H
#define __CVC4__EXPR_H

#include <string>
#include <iostream>
#include <stdint.h>

${includes}

// This is a hack, but an important one: if there's an error, the
// compiler directs the user to the template file instead of the
// generated one.  We don't want the user to modify the generated one,
// since it'll get overwritten on a later build.
#line 35 "${template}"

namespace CVC4 {

// The internal expression representation
template <bool ref_count>
class NodeTemplate;

/**
 * Class encapsulating CVC4 expressions and methods for constructing new
 * expressions.
 */
class CVC4_PUBLIC Expr {
protected:

  /** The internal expression representation */
  NodeTemplate<true>* d_node;

  /** The responsible expression manager */
  ExprManager* d_exprManager;

  /**
   * Constructor for internal purposes.
   * @param em the expression manager that handles this expression
   * @param node the actual expression node pointer
   */
  Expr(ExprManager* em, NodeTemplate<true>* node);

public:

  /** Default constructor, makes a null expression. */
  Expr();

  /**
   * Copy constructor, makes a copy of a given expression
   * @param e the expression to copy
   */
  Expr(const Expr& e);

  /**
   * Initialize from an integer. Fails if the integer is not 0.
   * NOTE: This is here purely to support the auto-initialization
   * behavior of the ANTLR3 C backend. Should be removed if future
   * versions of ANTLR fix the problem.
   */
  Expr(uintptr_t n);

  /** Destructor */
  ~Expr();

  /**
   * Assignment operator, makes a copy of the given expression. If the
   * expression managers of the two expressions differ, the expression of
   * the given expression will be used.
   * @param e the expression to assign
   * @return the reference to this expression after assignment
   */
  Expr& operator=(const Expr& e);

  /**
   * Syntactic comparison operator. Returns true if expressions belong to the
   * same expression manager and are syntactically identical.
   * @param e the expression to compare to
   * @return true if expressions are syntactically the same, false otherwise
   */
  bool operator==(const Expr& e) const;

  /**
   * Syntactic dis-equality operator.
   * @param e the expression to compare to
   * @return true if expressions differ syntactically, false otherwise
   */
  bool operator!=(const Expr& e) const;

  /**
   * Order comparison operator. The only invariant on the order of expressions
   * is that the expressions that were created sooner will be smaller in the
   * ordering than all the expressions created later. Null expression is the
   * smallest element of the ordering. The behavior of the operator is
   * undefined if the expressions come from two different expression managers.
   * @param e the expression to compare to
   * @return true if this expression is smaller than the given one
   */
  bool operator<(const Expr& e) const;

  /**
   * Returns the kind of the expression (AND, PLUS ...).
   * @return the kind of the expression
   */
  Kind getKind() const;

  /**
   * Returns the number of children of this expression.
   * @return the number of children
   */
  size_t getNumChildren() const;

  /**
   * Check if this is an expression that has an operator.
   * @return true if this expression has an operator
   */
  bool hasOperator() const;

  /**
   * Get the operator of this expression.
   * @throws IllegalArgumentException if it has no operator
   * @return the operator of this expression
   */
  Expr getOperator() const;

  /** Returns the type of the expression, if it has been computed.
   * Returns NULL if the type of the expression is not known.
   */
  Type* getType() const;

  /**
   * Returns the string representation of the expression.
   * @return a string representation of the expression
   */
  std::string toString() const;

  /**
   * Outputs the string representation of the expression to the stream.
   * @param out the output stream
   */
  void toStream(std::ostream& out) const;

  /**
   * Check if this is a null expression.
   * @return true if a null expression
   */
  bool isNull() const;

  /**
   * Check if this is a null expression.
   * @return true if NOT a null expression
   */
  operator bool() const;

  /**
   * Check if this is an expression representing a constant.
   * @return true if a constant expression
   */
  bool isConst() const;

  /**
   * Check if this is an expression representing a constant.
   * @return true if a constant expression
   */
  bool isAtomic() const;

  /** Extract a constant of type T */
  template <class T>
  const T& getConst() const;

  /**
   * Returns the expression reponsible for this expression.
   */
  ExprManager* getExprManager() const;

  /**
   * Very basic pretty printer for Expr.
   * This is equivalent to calling e.getNode().printAst(...)
   * @param out output stream to print to.
   * @param indent number of spaces to indent the formula by.
   */
  void printAst(std::ostream& out, int indent = 0) const;

private:

  /**
   * Pretty printer for use within gdb
   * This is not intended to be used outside of gdb.
   * This writes to the ostream Warning() and immediately flushes
   * the ostream.
   */
  void debugPrint();

protected:

  /**
   * Returns the actual internal node.
   * @return the internal node
   */
  NodeTemplate<true> getNode() const;

  // Friend to access the actual internal node information and private methods
  friend class SmtEngine;
  friend class ExprManager;
};

/**
 * Output operator for expressions
 * @param out the stream to output to
 * @param e the expression to output
 * @return the stream
 */
std::ostream& operator<<(std::ostream& out, const Expr& e) CVC4_PUBLIC;

/**
 * Extending the expression with the capability to construct Boolean
 * expressions.
 */
class CVC4_PUBLIC BoolExpr : public Expr {

public:

  /** Default constructor, makes a null expression */
  BoolExpr();

  /**
   * Convert an expression to a Boolean expression
   */
  BoolExpr(const Expr& e);

  /**
   * Negate this expression.
   * @return the logical negation of this expression.
   */
  BoolExpr notExpr() const;

  /**
   * Conjunct the given expression to this expression.
   * @param e the expression to conjunct
   * @return the conjunction of this expression and e
   */
  BoolExpr andExpr(const BoolExpr& e) const;

  /**
   * Disjunct the given expression to this expression.
   * @param e the expression to disjunct
   * @return the disjunction of this expression and e
   */
  BoolExpr orExpr(const BoolExpr& e) const;

  /**
   * Make an exclusive or expression out of this expression and the given
   * expression.
   * @param e the right side of the xor
   * @return the xor of this expression and e
   */
  BoolExpr xorExpr(const BoolExpr& e) const;

  /**
   * Make an equivalence expression out of this expression and the given
   * expression.
   * @param e the right side of the equivalence
   * @return the equivalence expression
   */
  BoolExpr iffExpr(const BoolExpr& e) const;

  /**
   * Make an implication expression out of this expression and the given
   * expression.
   * @param e the right side of the equivalence
   * @return the equivalence expression
   */
  BoolExpr impExpr(const BoolExpr& e) const;

  /**
   * Make a Boolean if-then-else expression using this expression as the
   * condition, and given the then and else parts
   * @param then_e the then branch expression
   * @param else_e the else branch expression
   * @return the if-then-else expression
   */
  BoolExpr iteExpr(const BoolExpr& then_e, const BoolExpr& else_e) const;

  /**
   * Make a term if-then-else expression using this expression as the
   * condition, and given the then and else parts
   * @param then_e the then branch expression
   * @param else_e the else branch expression
   * @return the if-then-else expression
   */
  Expr iteExpr(const Expr& then_e, const Expr& else_e) const;
};

${getConst_instantiations}

}/* CVC4 namespace */

#endif /* __CVC4__EXPR_H */
