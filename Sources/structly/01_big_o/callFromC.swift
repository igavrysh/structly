//
//  callFromC.swift
//  MyCLI
//
//  Created by new on 3/4/26.
//

import structlyC

public func callCpp() {
    run_cpp_logic()
    run1()
    run2()
    run3();
    run4();
    run5();
    run6();

    function1(100);

    let vec = StructlyBridge.function2(100);
    for i in 0..<vec.size() {
        print(vec[i])
    }
    let swiftArray = Array(vec)
    print("returned swiftArray: \(swiftArray)")

//    StructlyBridge.function3(100);
    //function4({"q", "r", "s"});
}
