(*
    This file is part of BinCAT.
    Copyright 2014-2017 - Airbus Group

    BinCAT is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    BinCAT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with BinCAT.  If not, see <http://www.gnu.org/licenses/>.
*)

open Data

type label = Asm.label
type concrete = Asm.concrete

(** Signature of abstract domains *)

module type T = 
    sig
	  include Domain.T
      
      (** top value *)
      val top: int -> t
		
      (** returns the size in bits of the concrete values this represents *)
      val get_size: t -> int
		 
      (** get an abstract value from a single concrete value *)
      val of_word: Word.t -> t

      (** get an abstract value from a single concrete value *)
      val of_reloc: Asm.reloc -> t

      (** get an abstract value from a single concrete value *)
      val of_concrete: concrete -> int -> t

      (** returns wether the first abstract value and n following values are
          necessarily between the following two abstract values. *)
      val is_between: t -> int -> t -> t -> bool

      val unop: Asm.unop -> t -> t
      val binop: Asm.binop -> t -> t -> t
      val cmp: Asm.cmp -> t -> t -> t
      val bunop: Asm.bunop -> t -> t
      val bbinop: Asm.logbinop -> t -> t -> t
      val get_singleton: t -> concrete
      val concretization: t -> concrete list
      val update_sub: t -> int -> int -> t -> t
      val get_sub: t -> int -> int -> t
    end
      
