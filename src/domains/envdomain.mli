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

(** Signature of abstract domains *)

module type T = 
    sig
	  include Domain.T

      (** top value *)
      val top: t

      (** Initial state of a function *)
      val start_state: Asm.reg -> t

      (** evaluates an expression and assigns the result to the register. *)
      val assign: t -> Asm.exp -> Asm.reg -> t

      (** load from memory at the address specified by the expression, and assigns
          the result to the register. *)
      val load: t -> Asm.exp -> Asm.reg -> t

      (** store the value of an expression to all addresses specified in the
          second expression. *)
      val store: t -> Asm.exp -> int -> Asm.exp -> t

      (** cleans the environment after a call. *)
      val callclean: t -> t

      (** Evaluates an expression in the current state *)
      val concrete_eval: t -> Asm.exp -> Numericaldomain.concrete list

      (** Evaluates a boolean expression in the current state *)
      val beval: t -> Asm.bexp -> Vector.bit

      (** Forget a register *)
      val forget_reg: t -> Asm.reg -> t
    end
