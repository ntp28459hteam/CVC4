; COMMAND-LINE: --no-check-proofs
(set-option :incremental false)
(set-info :source "The Formal Verification of a Reintegration Protocol. Author: Lee Pike. Website: http://www.cs.indiana.edu/~lepike/pub_pages/emsoft.html.

This benchmark was automatically translated into SMT-LIB format from
CVC format using CVC Lite")
(set-info :status unsat)
(set-info :category "industrial")
(set-info :difficulty "0")
(set-logic QF_LRA)
(declare-fun x_0 () Real)
(declare-fun x_1 () Bool)
(declare-fun x_2 () Real)
(declare-fun x_3 () Real)
(declare-fun x_4 () Bool)
(declare-fun x_5 () Real)
(declare-fun x_6 () Bool)
(declare-fun x_7 () Bool)
(declare-fun x_8 () Bool)
(declare-fun x_9 () Real)
(declare-fun x_10 () Real)
(declare-fun x_11 () Bool)
(declare-fun x_12 () Bool)
(declare-fun x_13 () Bool)
(declare-fun x_14 () Bool)
(declare-fun x_15 () Bool)
(declare-fun x_16 () Bool)
(declare-fun x_17 () Real)
(declare-fun x_18 () Real)
(declare-fun x_19 () Real)
(declare-fun x_20 () Real)
(declare-fun x_21 () Bool)
(declare-fun x_22 () Bool)
(declare-fun x_23 () Bool)
(declare-fun x_24 () Bool)
(declare-fun x_25 () Bool)
(declare-fun x_26 () Real)
(declare-fun x_27 () Real)
(declare-fun x_28 () Bool)
(declare-fun x_29 () Bool)
(declare-fun x_30 () Real)
(declare-fun x_31 () Real)
(declare-fun x_32 () Real)
(declare-fun x_33 () Real)
(declare-fun x_34 () Real)
(declare-fun x_35 () Real)
(declare-fun x_36 () Real)
(declare-fun x_37 () Bool)
(declare-fun x_38 () Bool)
(declare-fun x_39 () Bool)
(declare-fun x_40 () Bool)
(declare-fun x_41 () Bool)
(declare-fun x_42 () Bool)
(declare-fun x_43 () Real)
(declare-fun x_44 () Real)
(declare-fun x_45 () Real)
(declare-fun x_46 () Real)
(declare-fun x_47 () Real)
(declare-fun x_48 () Real)
(declare-fun x_49 () Real)
(declare-fun x_50 () Real)
(declare-fun x_51 () Real)
(declare-fun x_52 () Real)
(declare-fun x_53 () Bool)
(declare-fun x_54 () Real)
(declare-fun x_55 () Real)
(declare-fun x_56 () Real)
(check-sat-assuming ( (let ((_let_0 (+ x_10 x_2))) (let ((_let_1 (<= x_9 x_26))) (let ((_let_2 (= x_14 x_6))) (let ((_let_3 (= x_17 0.0))) (let ((_let_4 (< x_9 x_27))) (let ((_let_5 (= x_26 x_9))) (let ((_let_6 (= x_17 2.0))) (let ((_let_7 (= x_28 x_29))) (let ((_let_8 (and (= x_21 x_11) (= x_22 x_12)))) (let ((_let_9 (= x_25 x_13))) (let ((_let_10 (and (= x_23 x_1) (= x_24 x_4)))) (let ((_let_11 (= x_30 x_31))) (let ((_let_12 (and (= x_32 x_33) (= x_34 x_35)))) (let ((_let_13 (= x_36 x_27))) (let ((_let_14 (= x_15 x_7))) (let ((_let_15 (= x_37 x_38))) (let ((_let_16 (and (= x_39 x_40) (= x_41 x_42)))) (let ((_let_17 (= x_16 x_8))) (let ((_let_18 (- x_18 x_10))) (let ((_let_19 (= x_17 1.0))) (let ((_let_20 (+ x_2 x_10))) (let ((_let_21 (<= x_43 x_26))) (let ((_let_22 (= x_28 (or x_29 (and _let_21 x_38))))) (let ((_let_23 (<= x_3 _let_0))) (let ((_let_24 (<= x_5 _let_0))) (let ((_let_25 (<= x_3 x_2))) (let ((_let_26 (<= x_5 x_2))) (let ((_let_27 (< x_3 x_9))) (let ((_let_28 (= x_26 x_3))) (let ((_let_29 (< x_5 x_9))) (let ((_let_30 (= x_26 x_5))) (let ((_let_31 (not _let_1))) (let ((_let_32 (and (= x_21 (or x_11 (and (and (not _let_25) (<= x_3 x_26)) x_40))) (= x_22 (or x_12 (and (and (not _let_26) (<= x_5 x_26)) x_42)))))) (let ((_let_33 (<= x_43 _let_0))) (let ((_let_34 (< x_43 x_9))) (let ((_let_35 (= x_26 x_43))) (let ((_let_36 (<= (ite x_13 (ite x_4 (ite x_1 3 2) x_44) (ite x_4 x_44 (ite x_1 1 0))) (* (* (ite x_29 (ite x_12 (ite x_11 0 1) x_45) (ite x_12 x_45 (ite x_11 2 3))) 1.0) (/ 1 2))))) (let ((_let_37 (not _let_23))) (let ((_let_38 (not _let_24))) (let ((_let_39 (and (not (<= x_43 x_2)) _let_21))) (let ((_let_40 (and (not (<= x_46 x_2)) (<= x_46 x_26)))) (let ((_let_41 (not _let_33))) (let ((_let_42 (= x_30 0.0))) (let ((_let_43 (= x_32 0.0))) (let ((_let_44 (= x_34 0.0))) (let ((_let_45 (not (= x_0 2.0)))) (let ((_let_46 (< x_2 x_3))) (let ((_let_47 (< x_2 x_5))) (let ((_let_48 (not _let_19))) (let ((_let_49 (not (<= x_18 x_19)))) (let ((_let_50 (not (<= x_18 x_20)))) (let ((_let_51 (< x_26 x_19))) (let ((_let_52 (< x_26 x_20))) (let ((_let_53 (= x_0 0.0))) (let ((_let_54 (not _let_53))) (let ((_let_55 (= x_0 1.0))) (let ((_let_56 (not _let_55))) (let ((_let_57 (and (not (<= x_49 x_2)) (<= x_49 x_26)))) (let ((_let_58 (= x_32 (ite (not x_11) (ite (and (and (not _let_25) (<= x_3 x_26)) (< x_33 3.0)) (+ x_33 1.0) x_33) x_33)))) (let ((_let_59 (= x_34 (ite (not x_12) (ite (and (and (not _let_26) (<= x_5 x_26)) (< x_35 3.0)) (+ x_35 1.0) x_35) x_35)))) (let ((_let_60 (or x_11 (= x_32 3.0)))) (let ((_let_61 (or x_12 (= x_34 3.0)))) (let ((_let_62 (or x_29 (= x_30 3.0)))) (let ((_let_63 (ite _let_39 2 1))) (let ((_let_64 (ite _let_39 3 2))) (let ((_let_65 (ite _let_39 1 0))) (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (<= x_17 2.0) (>= x_17 0.0)) (<= x_0 2.0)) (>= x_0 0.0)) (>= x_2 0.0)) (>= x_3 0.0)) (>= x_5 0.0)) (>= x_9 0.0)) (> x_10 0.0)) (>= x_10 0.0)) (>= x_18 0.0)) (>= x_19 0.0)) (>= x_20 0.0)) (>= x_26 0.0)) (>= x_27 0.0)) (or (or (or _let_42 (= x_30 1.0)) (= x_30 2.0)) (= x_30 3.0))) (not (< x_30 0.0))) (<= x_30 3.0)) (or (or (or (= x_31 0.0) (= x_31 1.0)) (= x_31 2.0)) (= x_31 3.0))) (not (< x_31 0.0))) (<= x_31 3.0)) (or (or (or _let_43 (= x_32 1.0)) (= x_32 2.0)) (= x_32 3.0))) (not (< x_32 0.0))) (<= x_32 3.0)) (or (or (or (= x_33 0.0) (= x_33 1.0)) (= x_33 2.0)) (= x_33 3.0))) (not (< x_33 0.0))) (<= x_33 3.0)) (or (or (or _let_44 (= x_34 1.0)) (= x_34 2.0)) (= x_34 3.0))) (not (< x_34 0.0))) (<= x_34 3.0)) (or (or (or (= x_35 0.0) (= x_35 1.0)) (= x_35 2.0)) (= x_35 3.0))) (not (< x_35 0.0))) (<= x_35 3.0)) (>= x_36 0.0)) (>= x_43 0.0)) (>= x_46 0.0)) (>= x_49 0.0)) (not (<= x_52 (* x_10 3.0)))) (>= x_52 0.0)) (>= x_54 0.0)) (>= x_55 0.0)) (>= x_56 0.0)) (or _let_45 (and (or x_1 _let_46) (or x_4 _let_47)))) (or (not _let_3) (and x_16 x_14))) (or _let_48 (and x_15 x_14))) (or (not _let_6) (and x_15 x_16))) _let_49) _let_50) (< (- x_18 x_19) x_10)) (< (- x_18 x_20) x_10)) (not x_21)) (not x_22)) (or _let_48 (and (and (not x_23) (not x_24)) (not x_25)))) (or (or _let_48 (not x_16)) (and _let_51 _let_52))) (or _let_54 (and x_8 x_6))) (or _let_56 (and x_7 x_6))) (or _let_45 (and x_7 x_8))) (not (<= x_9 x_3))) (not (<= x_9 x_5))) (< (- x_9 x_3) x_10)) (< (- x_9 x_5) x_10)) (not x_11)) (not x_12)) (or _let_56 (and (and (not x_1) (not x_4)) (not x_13)))) (or (or _let_56 (not x_8)) (and _let_46 _let_47))) (= x_44 (/ (ite x_1 2 1) 1))) (= x_45 (/ (ite x_11 1 2) 1))) (= x_47 (/ _let_63 1))) (= x_48 (/ _let_63 1))) (= x_50 (+ (ite _let_57 (ite _let_40 _let_64 x_47) (ite _let_40 x_47 _let_65)) x_31))) (= x_51 (+ (ite _let_57 (ite _let_40 _let_64 x_48) (ite _let_40 x_48 _let_65)) x_31))) (or (or (and (and (and (and (and (and (or (and (and (and (and (and (and (and (and (and (and _let_3 _let_4) _let_5) _let_58) _let_59) (= x_30 (ite (not x_29) (ite (not (< x_50 3.0)) 3 x_50) x_31))) (= x_21 _let_60)) (= x_22 _let_61)) (= x_28 _let_62)) _let_14) _let_13) (and (and (and (and (and (and (and (and (and (and _let_3 (not _let_4)) x_15) (= x_26 x_27)) _let_58) _let_59) (= x_30 (ite (not x_29) (ite (not (< x_51 3.0)) 3 x_51) x_31))) (= x_21 (or _let_60 _let_43))) (= x_22 (or _let_61 _let_44))) (= x_28 (or _let_62 _let_42))) _let_13)) _let_15) _let_16) _let_17) _let_9) _let_10) _let_2) (and (and (and (and (and (and (and (or (and (and (and (and (and (and (and (and (and (and (and _let_19 (or (or (and (and (and (not _let_25) (not x_11)) (not x_40)) _let_23) (and (and (and (not _let_26) (not x_12)) (not x_42)) _let_24)) (and (and (not x_29) (not x_38)) _let_33))) (not x_16)) (or (or (or (or _let_25 _let_37) x_40) x_11) (not (< x_26 x_3)))) (or (or (or (or _let_26 _let_38) x_42) x_12) (not (< x_26 x_5)))) (or (or (or _let_41 x_38) x_29) (not (< x_26 x_43)))) (or (or (or (and (and (and (and (not x_40) (not x_11)) _let_23) _let_27) _let_28) (and (and (and (and (not x_42) (not x_12)) _let_24) _let_29) _let_30)) (and (and (and (and (not x_38) (not x_29)) _let_33) _let_34) _let_35)) (and (< x_9 _let_20) _let_5))) (= x_39 (or x_40 (and (not _let_25) (<= x_3 x_26))))) (= x_41 (or x_42 (and (not _let_26) (<= x_5 x_26))))) (= x_37 (or x_38 _let_21))) _let_32) _let_22) (and (and (and (and (and (and (and (and (and _let_19 (or (or (or _let_25 x_40) x_11) _let_37)) (or (or (or _let_26 x_42) x_12) _let_38)) (or (or x_38 x_29) _let_41)) x_16) (= x_26 _let_20)) _let_32) _let_22) _let_15) _let_16)) _let_11) _let_12) _let_13) _let_14) _let_9) _let_10) _let_2)) (and (and (and (and (and (and (and (or (and (and (and (and (and (and (and (and (and (and (and _let_6 _let_36) (not x_14)) (or (or (or _let_25 x_1) x_11) (<= x_26 x_3))) (or (or (or _let_26 x_4) x_12) (<= x_26 x_5))) (or (or x_13 x_29) (<= x_26 x_43))) (or (or (or (and (and (and (and (not x_1) (not x_11)) _let_46) _let_27) _let_28) (and (and (and (and (not x_4) (not x_12)) _let_47) _let_29) _let_30)) (and (and (and (not x_13) (not x_29)) _let_34) _let_35)) _let_5)) (= x_23 (or x_1 (= x_3 x_26)))) (= x_24 (or x_4 (= x_5 x_26)))) (= x_25 (or x_13 (= x_43 x_26)))) _let_7) _let_8) (and (and (and (and (and (and (and _let_6 (not _let_36)) x_14) _let_7) _let_8) (= x_26 x_2)) _let_9) _let_10)) _let_11) _let_12) _let_13) _let_14) _let_15) _let_16) _let_17))) (or (or (and _let_53 (= x_17 (ite (not x_7) x_0 1))) (and _let_55 (= x_17 (ite (not x_8) x_0 2)))) (and (and _let_54 _let_56) (= x_17 x_0)))) (or (and (and _let_1 _let_49) (not (<= x_19 _let_18))) (and _let_31 (= x_19 x_3)))) (or (and (and _let_1 _let_50) (not (<= x_20 _let_18))) (and _let_31 (= x_20 x_5)))) (or (and (and _let_1 (= x_18 (+ x_9 x_52))) x_53) (and (and _let_31 (not x_53)) (= x_18 x_9)))) (or (and (and (and (and _let_21 (not (<= x_54 x_26))) (not (<= x_55 x_26))) (< x_54 x_55)) (< x_55 x_56)) (and (and (and (not _let_21) (= x_54 x_43)) (= x_55 x_46)) (= x_56 x_49)))) _let_6) (or (and (not x_23) (not _let_51)) (and (not x_24) (not _let_52)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ))
