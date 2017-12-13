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

(** raised when the address to compute has an unexpected format *)
exception Illegal_address                

(** raised when an abstract operation produces an empty value *)
exception Empty of string

(** raised when a concretization computes a too large result *)
exception Too_many_concrete_elements of string

(** raised when an unexpected behavior happens (undefined decoding, etc.) *)
exception Error of string

(** raised when an undefine dereference occurs *)
exception Bot_deref

(** raised when the analysis thinks an illegal step can occur *)
exception Abstract_policy of string
