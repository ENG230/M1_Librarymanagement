#include"Library_management.h"
#include"unity_internals.h"
#include"unity.h"

void setUp(){

}

void tearDown(){

}


void test_ToAddingBook(void){
    TEST_ASSERT_EQUAL(pass,(409, "ARUN", "PYTHON"));
}

void test_ToViewBook(void){
    TEST_ASSERT_EQUAL(pass,ToViewBook());
}

void test_ToSearchingBook(void){
    TEST_ASSERT_EQUAL(fail,ToSearchingBook(-10));
    TEST_ASSERT_EQUAL(pass,ToSearchingBook(409));
}



void test_ToDeletingBook(void){
    TEST_ASSERT_EQUAL(pass,ToDeletingBook(409));
}        



int main(){
    UNITY_BEGIN();

    RUN_TEST(test_ToAddingBook);
    RUN_TEST(test_ToSearchingBook);
    RUN_TEST(test_ToDeletingBook);
    RUN_TEST(test_ToViewBook);
    
    return UNITY_END();
}