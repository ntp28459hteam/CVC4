/*********************                                                        */
/*! \file sort_black.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Aina Niemetz
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2019 by the authors listed in the file AUTHORS
 ** in the top-level source directory) and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief Black box testing of the guards of the C++ API functions.
 **
 ** Black box testing of the guards of the C++ API functions.
 **/

#include <cxxtest/TestSuite.h>

#include "api/cvc4cpp.h"

using namespace CVC4::api;

class SortBlack : public CxxTest::TestSuite
{
 public:
  void setUp() override;
  void tearDown() override;

  void testGetDatatype();
  void testInstantiate();
  void testGetFunctionArity();
  void testGetFunctionDomainSorts();
  void testGetFunctionCodomainSort();
  void testGetArrayIndexSort();
  void testGetArrayElementSort();
  void testGetSetElementSort();
  void testGetUninterpretedSortName();
  void testIsUninterpretedSortParameterized();
  void testGetUninterpretedSortParamSorts();
  void testGetUninterpretedSortConstructorName();
  void testGetUninterpretedSortConstructorArity();
  void testGetBVSize();
  void testGetFPExponentSize();
  void testGetFPSignificandSize();
  void testGetDatatypeParamSorts();
  void testGetDatatypeArity();
  void testGetTupleLength();
  void testGetTupleSorts();

 private:
  Solver d_solver;
};

void SortBlack::setUp() {}

void SortBlack::tearDown() {}

void SortBlack::testGetDatatype()
{
  // create datatype sort, check should not fail
  DatatypeDecl dtypeSpec = d_solver.mkDatatypeDecl("list");
  DatatypeConstructorDecl cons("cons");
  DatatypeSelectorDecl head("head", d_solver.getIntegerSort());
  cons.addSelector(head);
  dtypeSpec.addConstructor(cons);
  DatatypeConstructorDecl nil("nil");
  dtypeSpec.addConstructor(nil);
  Sort dtypeSort = d_solver.mkDatatypeSort(dtypeSpec);
  TS_ASSERT_THROWS_NOTHING(dtypeSort.getDatatype());
  // create bv sort, check should fail
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getDatatype(), CVC4ApiException&);
}

void SortBlack::testInstantiate()
{
  // instantiate parametric datatype, check should not fail
  Sort sort = d_solver.mkParamSort("T");
  DatatypeDecl paramDtypeSpec = d_solver.mkDatatypeDecl("paramlist", sort);
  DatatypeConstructorDecl paramCons("cons");
  DatatypeConstructorDecl paramNil("nil");
  DatatypeSelectorDecl paramHead("head", sort);
  paramCons.addSelector(paramHead);
  paramDtypeSpec.addConstructor(paramCons);
  paramDtypeSpec.addConstructor(paramNil);
  Sort paramDtypeSort = d_solver.mkDatatypeSort(paramDtypeSpec);
  TS_ASSERT_THROWS_NOTHING(
      paramDtypeSort.instantiate(std::vector<Sort>{d_solver.getIntegerSort()}));
  // instantiate non-parametric datatype sort, check should fail
  DatatypeDecl dtypeSpec = d_solver.mkDatatypeDecl("list");
  DatatypeConstructorDecl cons("cons");
  DatatypeSelectorDecl head("head", d_solver.getIntegerSort());
  cons.addSelector(head);
  dtypeSpec.addConstructor(cons);
  DatatypeConstructorDecl nil("nil");
  dtypeSpec.addConstructor(nil);
  Sort dtypeSort = d_solver.mkDatatypeSort(dtypeSpec);
  TS_ASSERT_THROWS(
      dtypeSort.instantiate(std::vector<Sort>{d_solver.getIntegerSort()}),
      CVC4ApiException&);
}

void SortBlack::testGetFunctionArity()
{
  Sort funSort = d_solver.mkFunctionSort(d_solver.mkUninterpretedSort("u"),
                                         d_solver.getIntegerSort());
  TS_ASSERT_THROWS_NOTHING(funSort.getFunctionArity());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getFunctionArity(), CVC4ApiException&);
}

void SortBlack::testGetFunctionDomainSorts()
{
  Sort funSort = d_solver.mkFunctionSort(d_solver.mkUninterpretedSort("u"),
                                         d_solver.getIntegerSort());
  TS_ASSERT_THROWS_NOTHING(funSort.getFunctionDomainSorts());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getFunctionDomainSorts(), CVC4ApiException&);
}

void SortBlack::testGetFunctionCodomainSort()
{
  Sort funSort = d_solver.mkFunctionSort(d_solver.mkUninterpretedSort("u"),
                                         d_solver.getIntegerSort());
  TS_ASSERT_THROWS_NOTHING(funSort.getFunctionCodomainSort());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getFunctionCodomainSort(), CVC4ApiException&);
}

void SortBlack::testGetArrayIndexSort()
{
  Sort elementSort = d_solver.mkBitVectorSort(32);
  Sort indexSort = d_solver.mkBitVectorSort(32);
  Sort arraySort = d_solver.mkArraySort(indexSort, elementSort);
  TS_ASSERT_THROWS_NOTHING(arraySort.getArrayIndexSort());
  TS_ASSERT_THROWS(indexSort.getArrayIndexSort(), CVC4ApiException&);
}

void SortBlack::testGetArrayElementSort()
{
  Sort elementSort = d_solver.mkBitVectorSort(32);
  Sort indexSort = d_solver.mkBitVectorSort(32);
  Sort arraySort = d_solver.mkArraySort(indexSort, elementSort);
  TS_ASSERT_THROWS_NOTHING(arraySort.getArrayElementSort());
  TS_ASSERT_THROWS(indexSort.getArrayElementSort(), CVC4ApiException&);
}

void SortBlack::testGetSetElementSort()
{
  Sort setSort = d_solver.mkSetSort(d_solver.getIntegerSort());
  TS_ASSERT_THROWS_NOTHING(setSort.getSetElementSort());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getSetElementSort(), CVC4ApiException&);
}

void SortBlack::testGetUninterpretedSortName()
{
  Sort uSort = d_solver.mkUninterpretedSort("u");
  TS_ASSERT_THROWS_NOTHING(uSort.getUninterpretedSortName());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getUninterpretedSortName(), CVC4ApiException&);
}

void SortBlack::testIsUninterpretedSortParameterized()
{
  Sort uSort = d_solver.mkUninterpretedSort("u");
  TS_ASSERT_THROWS_NOTHING(uSort.isUninterpretedSortParameterized());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.isUninterpretedSortParameterized(),
                   CVC4ApiException&);
}

void SortBlack::testGetUninterpretedSortParamSorts()
{
  Sort uSort = d_solver.mkUninterpretedSort("u");
  TS_ASSERT_THROWS_NOTHING(uSort.getUninterpretedSortParamSorts());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getUninterpretedSortParamSorts(), CVC4ApiException&);
}

void SortBlack::testGetUninterpretedSortConstructorName()
{
  Sort sSort = d_solver.mkSortConstructorSort("s", 2);
  TS_ASSERT_THROWS_NOTHING(sSort.getSortConstructorName());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getSortConstructorName(), CVC4ApiException&);
}

void SortBlack::testGetUninterpretedSortConstructorArity()
{
  Sort sSort = d_solver.mkSortConstructorSort("s", 2);
  TS_ASSERT_THROWS_NOTHING(sSort.getSortConstructorArity());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getSortConstructorArity(), CVC4ApiException&);
}

void SortBlack::testGetBVSize()
{
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS_NOTHING(bvSort.getBVSize());
  Sort setSort = d_solver.mkSetSort(d_solver.getIntegerSort());
  TS_ASSERT_THROWS(setSort.getBVSize(), CVC4ApiException&);
}

void SortBlack::testGetFPExponentSize()
{
  Sort fpSort = d_solver.mkFloatingPointSort(4, 8);
  TS_ASSERT_THROWS_NOTHING(fpSort.getFPExponentSize());
  Sort setSort = d_solver.mkSetSort(d_solver.getIntegerSort());
  TS_ASSERT_THROWS(setSort.getFPExponentSize(), CVC4ApiException&);
}

void SortBlack::testGetFPSignificandSize()
{
  Sort fpSort = d_solver.mkFloatingPointSort(4, 8);
  TS_ASSERT_THROWS_NOTHING(fpSort.getFPSignificandSize());
  Sort setSort = d_solver.mkSetSort(d_solver.getIntegerSort());
  TS_ASSERT_THROWS(setSort.getFPSignificandSize(), CVC4ApiException&);
}

void SortBlack::testGetDatatypeParamSorts()
{
  // create parametric datatype, check should not fail
  Sort sort = d_solver.mkParamSort("T");
  DatatypeDecl paramDtypeSpec = d_solver.mkDatatypeDecl("paramlist", sort);
  DatatypeConstructorDecl paramCons("cons");
  DatatypeConstructorDecl paramNil("nil");
  DatatypeSelectorDecl paramHead("head", sort);
  paramCons.addSelector(paramHead);
  paramDtypeSpec.addConstructor(paramCons);
  paramDtypeSpec.addConstructor(paramNil);
  Sort paramDtypeSort = d_solver.mkDatatypeSort(paramDtypeSpec);
  TS_ASSERT_THROWS_NOTHING(paramDtypeSort.getDatatypeParamSorts());
  // create non-parametric datatype sort, check should fail
  DatatypeDecl dtypeSpec = d_solver.mkDatatypeDecl("list");
  DatatypeConstructorDecl cons("cons");
  DatatypeSelectorDecl head("head", d_solver.getIntegerSort());
  cons.addSelector(head);
  dtypeSpec.addConstructor(cons);
  DatatypeConstructorDecl nil("nil");
  dtypeSpec.addConstructor(nil);
  Sort dtypeSort = d_solver.mkDatatypeSort(dtypeSpec);
  TS_ASSERT_THROWS(dtypeSort.getDatatypeParamSorts(), CVC4ApiException&);
}

void SortBlack::testGetDatatypeArity()
{
  // create datatype sort, check should not fail
  DatatypeDecl dtypeSpec = d_solver.mkDatatypeDecl("list");
  DatatypeConstructorDecl cons("cons");
  DatatypeSelectorDecl head("head", d_solver.getIntegerSort());
  cons.addSelector(head);
  dtypeSpec.addConstructor(cons);
  DatatypeConstructorDecl nil("nil");
  dtypeSpec.addConstructor(nil);
  Sort dtypeSort = d_solver.mkDatatypeSort(dtypeSpec);
  TS_ASSERT_THROWS_NOTHING(dtypeSort.getDatatypeArity());
  // create bv sort, check should fail
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getDatatypeArity(), CVC4ApiException&);
}

void SortBlack::testGetTupleLength()
{
  Sort tupleSort = d_solver.mkTupleSort(
      {d_solver.getIntegerSort(), d_solver.getIntegerSort()});
  TS_ASSERT_THROWS_NOTHING(tupleSort.getTupleLength());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getTupleLength(), CVC4ApiException&);
}

void SortBlack::testGetTupleSorts()
{
  Sort tupleSort = d_solver.mkTupleSort(
      {d_solver.getIntegerSort(), d_solver.getIntegerSort()});
  TS_ASSERT_THROWS_NOTHING(tupleSort.getTupleSorts());
  Sort bvSort = d_solver.mkBitVectorSort(32);
  TS_ASSERT_THROWS(bvSort.getTupleSorts(), CVC4ApiException&);
}
