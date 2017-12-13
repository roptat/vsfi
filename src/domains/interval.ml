
(** data type: int with infty *)
type iint =
  | MINF
  | INF
  | Num of int

(** data type: strided interval *)
type interv = int * iint * iint

let iint_le a b =
  match a, b with
  | MINF, _ -> true
  | INF, INF -> true
  | INF, _ -> false
  | Num a, INF -> true
  | Num a, MINF -> false
  | Num a, Num b -> a <= b

let iint_lt a b =
  match a, b with
  | MINF, MINF -> false
  | MINF, _ -> true
  | INF, _ -> false
  | Num a, INF -> true
  | Num a, MINF -> false
  | Num a, Num b -> a < b

module Make =
  (struct
    type t = interv

    let top:t = (1, MINF, INF)

    let bot = (1, INF, MINF)

    let init = bot

    let is_bot v =
      match v with
      | (stride, min, max) -> iint_lt max min

    let is_top v =
      v = top

    let forget v = top

    let is_subset v1 v2 =
      match v1, v2 with
      | (stride1, min1, max1), (stride2, min2, max2) ->
        match min1, max1, min2, max2 with
        | MINF, MINF, _, _ -> true
        | _, _, MINF, MINF -> false
        | _, _, MINF, INF -> true
        | MINF, Num max1, MINF, Num max2 -> max2 >= max1 && ((max2 - max1) mod stride1 = 0)
        | MINF, Num max1, MINF, _ -> false
        | MINF, INF, MINF, INF -> true
        | MINF, INF, MINF, _ -> false

    let to_string v =
      match v with
      | (stride, min, max) -> Printf.sprintf "%d[%d:%d]" stride min max

    let join v1 v2 =
      match v1, v2 with
      | (stride1, min1, max1), (stride2, min2, max2)

    end: Domain.T)
