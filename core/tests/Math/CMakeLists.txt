#Tests for Math Classes

add_executable(BivarStats_T BivarStats_T.cpp)
target_link_libraries(BivarStats_T gnsstk)
add_test(NAME Math_BivarStats COMMAND $<TARGET_FILE:BivarStats_T>)

add_executable(MathBase_T MathBase_T.cpp)
target_link_libraries(MathBase_T gnsstk)
add_test(NAME Math_MathBase COMMAND $<TARGET_FILE:MathBase_T>)

add_executable(Matrix_Initialization_T Matrix_Initialization_T.cpp)
target_link_libraries(Matrix_Initialization_T gnsstk)
add_test(NAME Math_Matrix_Initialization COMMAND $<TARGET_FILE:Matrix_Initialization_T>)

add_executable(Matrix_Operators_T Matrix_Operators_T.cpp)
target_link_libraries(Matrix_Operators_T gnsstk)
add_test(NAME Math_Matrix_Operators COMMAND $<TARGET_FILE:Matrix_Operators_T>)

add_executable(Matrix_Sizing_T Matrix_Sizing_T.cpp)
target_link_libraries(Matrix_Sizing_T gnsstk)
add_test(NAME Math_Matrix_Sizing COMMAND $<TARGET_FILE:Matrix_Sizing_T>)

add_executable(Matrix_InverseTranspose_T Matrix_InverseTranspose_T.cpp)
target_link_libraries(Matrix_InverseTranspose_T gnsstk)
add_test(NAME Math_Matrix_InverseTranspose COMMAND $<TARGET_FILE:Matrix_InverseTranspose_T>)

add_executable(Matrix_LUDecomp_T Matrix_LUDecomp_T.cpp)
target_link_libraries(Matrix_LUDecomp_T gnsstk)
add_test(NAME Math_Matrix_LUDecomp COMMAND $<TARGET_FILE:Matrix_LUDecomp_T>)

add_executable(Matrix_HouseHolder_T Matrix_HouseHolder_T.cpp)
target_link_libraries(Matrix_HouseHolder_T gnsstk)
add_test(NAME Math_Matrix_HouseHolder COMMAND $<TARGET_FILE:Matrix_HouseHolder_T>)

add_executable(Matrix_Cholesky_T Matrix_Cholesky_T.cpp)
target_link_libraries(Matrix_Cholesky_T gnsstk)
add_test(NAME Math_Matrix_Cholesky COMMAND $<TARGET_FILE:Matrix_Cholesky_T>)

add_executable(Matrix_SVD_T Matrix_SVD_T.cpp)
target_link_libraries(Matrix_SVD_T gnsstk)
add_test(NAME Math_Matrix_SVD COMMAND $<TARGET_FILE:Matrix_SVD_T>)

add_executable(MiscMath_T MiscMath_T.cpp)
target_link_libraries(MiscMath_T gnsstk)
add_test(NAME Math_MiscMath COMMAND $<TARGET_FILE:MiscMath_T>)

add_executable(PolyFit_T PolyFit_T.cpp)
target_link_libraries(PolyFit_T gnsstk)
add_test(NAME Math_PolyFit COMMAND $<TARGET_FILE:PolyFit_T>)

add_executable(RACRotation_T RACRotation_T.cpp)
target_link_libraries(RACRotation_T gnsstk)
add_test(NAME Math_RACRotation COMMAND $<TARGET_FILE:RACRotation_T>)

add_executable(Stats_T Stats_T.cpp)
target_link_libraries(Stats_T gnsstk)
add_test(NAME Math_Stats COMMAND $<TARGET_FILE:Stats_T>)

add_executable(Stats_TwoSampleStats_T Stats_TwoSampleStats_T.cpp)
target_link_libraries(Stats_TwoSampleStats_T gnsstk)
add_test(NAME Math_Stats_TwoSampleStats COMMAND $<TARGET_FILE:Stats_TwoSampleStats_T>)

add_executable(Triple_T Triple_T.cpp)
target_link_libraries(Triple_T gnsstk)
add_test(NAME Math_Triple COMMAND $<TARGET_FILE:Triple_T>)

add_executable(Vector_T Vector_T.cpp)
target_link_libraries(Vector_T gnsstk)
add_test(NAME Math_Vector COMMAND $<TARGET_FILE:Vector_T>)

add_executable(PowerSum_T PowerSum_T.cpp)
target_link_libraries(PowerSum_T gnsstk)
add_test(NAME PowerSum_T COMMAND PowerSum_T)
