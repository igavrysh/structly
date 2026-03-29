//
//  AllUnique.swift
//  MyCLI
//
//  Created by new on 3/13/26.
//

func allUnique(_ items: [String]) -> Bool {
    let set = Set(items)
    return set.count == items.count
}
