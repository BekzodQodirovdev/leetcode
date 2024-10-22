/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  function getNum(n) {
    let res = "";
    while (n !== null) {
      res = n.val + res;
      n = n.next;
    }
    return BigInt(res);
  }

  let n = getNum(l1);
  let m = getNum(l2);
  let resSum = n + m;

  let resStr = resSum.toString();
  let res = new ListNode(parseInt(resStr[resStr.length - 1]));
  let current = res;

  for (let i = resStr.length - 2; i >= 0; i--) {
    current.next = new ListNode(parseInt(resStr[i]));
    current = current.next;
  }

  return res;
};
